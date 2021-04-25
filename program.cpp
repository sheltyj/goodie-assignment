#include<bits/stdc++.h>
using namespace std;

bool myCompare(pair<string, int>  p1, pair<string, int> p2)
{
	return p1.second<p2.second;
}

int main()
{   

   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input3.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output3.txt", "w", stdout);
   #endif
	string  no; // number of total goodies
	getline(cin,no);
	int n=stoi(no);
	vector<pair<string,int> > store;  // store of goodies with their prices
	for(int i=0;i<n;i++) 
	{   
		string namePrice;
		getline(cin,namePrice);
		

		string name="";
		int j=0;
		while(namePrice[j]!=':')
		{   
			name+=namePrice[j];
			j++;
		}
		j+=2;  // for avoiding colon and space
		int price=0;
		while(j<namePrice.size())
		{
			char ch = namePrice[j];
			price = price*10 + (ch-'0');
			j++;
		}
		store.push_back({name,price});
	}
	sort(store.begin(), store.end(), myCompare); // sorting of goodies in ascending order according to their price

	int q; // no of queries
	cin>>q;
	while(q--)
	{   

		int noOfEmployees; // no of employees
		cin>>noOfEmployees;
		cout<<"no of employees: "<<noOfEmployees<<endl;
		cout<<endl;

		int diff=INT_MAX;
		int ansL=-1,ansR=-1;
	
		for(int i=noOfEmployees-1;i<n;i++)
		{
			int currDiff = store[i].second - store[i-noOfEmployees+1].second;
			if(currDiff<diff)
			{
				diff=currDiff;
				ansL=i-noOfEmployees+1;
				ansR=i;
			}
		}
		cout<<"distribution:-"<<endl;
		for(int i=ansL;i<=ansR;i++)
		{   
			string name=store[i].first;
			int price=store[i].second;
			cout<<name<<": "<<price<<endl;
		}
        cout<<endl;
        cout<<"difference: "<<diff<<endl;
        cout<<endl<<endl;
	}

}