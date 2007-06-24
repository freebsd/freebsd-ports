/*
Under Gnome, drag file into the playlist will pass a URL as filename (like file:///tmp/url%20encoded.ape)
The plugin cannot cope with URL originally, and this is the patch.

-buganini@gmail.com
*/

#include "string.h"

static char *url2filename(char *url){
	unsigned char *rpt,*wpt;
	char flag=0;
	unsigned char table[128]={0};
	
	if(strncmp(url,"file://",7)!=0){
		return url;
	}
	table[(unsigned char)'0']=0;
	table[(unsigned char)'1']=1;
	table[(unsigned char)'2']=2;
	table[(unsigned char)'3']=3;
	table[(unsigned char)'4']=4;
	table[(unsigned char)'5']=5;
	table[(unsigned char)'6']=6;
	table[(unsigned char)'7']=7;
	table[(unsigned char)'8']=8;
	table[(unsigned char)'9']=9;
	table[(unsigned char)'a']=table[(unsigned char)'A']=10;
	table[(unsigned char)'b']=table[(unsigned char)'B']=11;
	table[(unsigned char)'c']=table[(unsigned char)'C']=12;
	table[(unsigned char)'d']=table[(unsigned char)'D']=13;
	table[(unsigned char)'e']=table[(unsigned char)'E']=14;
	table[(unsigned char)'f']=table[(unsigned char)'F']=15;

	rpt=wpt=(unsigned char*)url;
	rpt+=7;
        while(*rpt!=0){
                if(flag==0){
                        if(*rpt=='%'){
                                flag=1;
                        }else{
                                *wpt=*rpt;
                                ++wpt;
                        }
                }else if(flag==1){
                        *wpt=table[*rpt]<<4;
                        flag=2;
                }else if(flag==2){
                        *wpt|=table[*rpt];
                        ++wpt;
                        flag=0;
                }
                ++rpt;
        }
        *wpt=0;
        return url;
}
