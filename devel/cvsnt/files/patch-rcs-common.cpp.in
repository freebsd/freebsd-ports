--- rcs/common.cpp.orig	Mon Oct  1 10:54:14 2007
+++ rcs/common.cpp	Mon Oct  1 10:56:12 2007
@@ -68,7 +68,7 @@
 	int n;
 	char **nargv = (char**)malloc((argc+3)*sizeof(char*));
 
-	nargv[0]="cvs";
+	nargv[0]="%%PREFIX%%/bin/cvs";
 	nargv[1]="rcsfile";
 	nargv[2]=(char*)command;
 	for(n=1; n<argc; n++)
