// https://www.geeksforgeeks.org/number-subsequences-string-divisible-n/
#include<bits/stdc++.h>
using namespace std;

int getCount(string s, int n, map<pair<int,int>,int> m, int idx, int rem){
    pair<int,int> key = pair<int,int>(idx,rem);
    if(m.find(key)!=m.end()){
        return m.find(key)->second;
    }
    
    int count = 0;

    if(idx==s.length()){
        count = rem==0?1:0;
        m.insert(pair<pair<int,int>,int>(key,count));
        return count;
    }

    count+=getCount(s, n, m, idx+1, rem);
    m.insert(pair<pair<int,int>,int>(key,count));

    int remidx = (rem*10 + (s[idx]-'0'))%n;

    count+=getCount(s, n, m, idx+1, remidx);
    
    key = pair<int,int>(idx,remidx);
    m.insert(pair<pair<int,int>,int>(key,count));

    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n;
    cin>>s>>n;
    
    map<pair<int,int>,int> m;
    int rem = 0, idx = 0;
    int count = getCount(s, n, m, idx, rem)-1;

    cout<<count<<endl;

    return 0;
}