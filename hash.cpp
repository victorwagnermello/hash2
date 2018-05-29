#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <map>
using namespace std;

int key(char *k)
{
	int n = 0, i;
	for(int i=0;k[i];i++)
		n = k[i]*(i+1)+n;
	n*= 19;
	return n % 101;
}

int add(int kkey, bool *flag)
{
	for(int j=0;j<=19;j++)
	
		if(!flag[(kkey + j*(j+23))%101])
			return (kkey + j*(j+23))%101;
			return -1;	
}

int main() 
{
	int t, n1, i, pos;
	char op[1000], str[30], input[100];
	string k, tab[101];
	scanf("%d",&t);
	while(t--)
	{
		map <string, int> 	N;
		bool flag[101] = {0};
		int total = 0;
		scanf("%d",&n1);
		for(i=0;i<n1;i++)
		{
			scanf("%s",input);
			strcpy(op,strtok(input,": "));
			strcpy(str,strtok(0,":"));
			k = str;
			if(!strcmp(op,"ADD"))
			{
				if(N.find(k)==N.end())
				{
					pos = add(key(str),flag);
					if(pos != -1)
					{
						total++;
						flag[pos] = 1;
						tab[pos] = k;
						N.insert(pair<string, int>(k, pos));
					}
				}
			}
			else if(!strcmp(op,"DEL"))
			{
				if(N.find(k)!=N.end())
				{
					flag[N[k]] = 0;
					N.erase(k);
					total--;
				}
			}
		}
		printf("%d\n",total);
		for(i=0;i<101;i++)
			if(flag[i])
				printf("%d:%s\n",i,tab[i].c_str());
	}
	return 0;
}
