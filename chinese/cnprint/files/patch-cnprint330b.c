--- cnprint330b.c.orig	Tue Jul  2 01:22:08 2002
+++ cnprint330b.c
@@ -6216,7 +6216,7 @@
 	if (s==NULL) {
 		defpath[0]='\0';
 #ifdef unix
-		strcpy(defpath, "/usr/local/src/cnprint");
+		strcpy(defpath, PREFIX "/share/cnprint");
 #endif
 		s=defpath;
 	}
