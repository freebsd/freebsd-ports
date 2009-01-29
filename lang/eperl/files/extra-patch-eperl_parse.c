--- eperl_parse.c.orig	2009-01-29 16:05:29.000000000 -0500
+++ eperl_parse.c	2009-01-29 16:05:37.000000000 -0500
@@ -326,16 +326,6 @@
     return NULL;
 }
 
-char *strndup(char *buf, int n)
-{
-    char *cp;
-
-    cp = (char *)malloc(n+1);
-    strncpy(cp, buf, n);
-    return cp;
-}
-
-
 /*
 **  convert buffer from bristled format to plain format
 */
