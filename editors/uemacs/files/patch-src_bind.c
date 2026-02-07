--- src/bind.c.orig	Sun Nov 19 03:09:20 1995
+++ src/bind.c	Wed Mar 25 15:00:37 1998
@@ -634,7 +634,8 @@
 	register char *sp;	/* pointer into path spec */
 	register int i; 	/* index */
 	static char fspec[NFILEN];	/* full path spec to search */
-
+        char patha[NFILEN];
+        
 	/* if we have an absolute path.. check only there! */
 	sp = fname;
 	while (*sp) {
@@ -689,9 +690,11 @@
 #if OS2
 	path = getenv("DPATH");
 #else
-	path = getenv("PATH");
+	strncpy(patha, getenv("PATH"), NFILEN - 25);
+        strcat(patha, ":%%PREFIX%%/share/uemacs");
 #endif
 #endif
+        path = patha;
 	if (path != NULL)
 		while (*path) {
 
