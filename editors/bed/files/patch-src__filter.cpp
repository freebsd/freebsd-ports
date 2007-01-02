--- src/filter.cpp.orig	Mon Jan 26 02:50:44 2004
+++ src/filter.cpp	Mon Jan  1 23:54:10 2007
@@ -42,13 +42,13 @@
 		if(filtersmaxlen>=filtersnr) {
 			filtersmaxlen=(filtersmaxlen+10)*2;
 			char **tmp=filtersnames;
-			filtersnames=new (char *)[filtersmaxlen];
+			filtersnames=new char *[filtersmaxlen];
 			if(tmp) {
 				memcpy(filtersnames,tmp,filtersnr*sizeof(char*));
 				delete[] tmp;
 				}
 			Filter *(**tmpfunc)(int,int,char*,ScreenPart *) =filtersfuncs;
-			filtersfuncs=new (Filter *(*)(int,int,char*,ScreenPart *))[filtersmaxlen];
+			filtersfuncs=new typeof(Filter *(*)(int,int,char*,ScreenPart *))[filtersmaxlen];
 			if(tmpfunc) {
 				memcpy(filtersfuncs,tmpfunc,filtersnr*sizeof(Filter *(*)(int,int,char*)));
 				delete[] tmpfunc;
