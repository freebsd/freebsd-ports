--- src/typelist.cc.orig	Thu May 23 16:28:24 2002
+++ src/typelist.cc	Mon Jan  1 23:55:30 2007
@@ -47,13 +47,13 @@
 		maxlen=(maxlen+10)*2;
 
 		char **tmp=names;
-		names=new (char *)[maxlen];
+		names=new char *[maxlen];
 		if(tmp) {
 			memcpy(names,tmp,nr*sizeof(char*));
 			delete[] tmp;
 			}
 		ScreenPart *(**tmpfunc)(Editor*) =funcs;
-		funcs=new (ScreenPart *(*)(Editor *))[maxlen];
+		funcs=new typeof(ScreenPart *(*)(Editor *))[maxlen];
 		if(tmpfunc) {
 			memcpy(funcs,tmpfunc,nr*sizeof(ScreenPart *(*)(Editor *)));
 			delete[] tmpfunc;
