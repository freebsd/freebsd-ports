
$FreeBSD$

--- eperl_parse.c	2001/12/19 14:40:20	1.1
+++ eperl_parse.c	2001/12/19 14:40:33
@@ -298,20 +298,6 @@
     return NULL;
 }
 
-char *strnstr(char *buf, char *str, int n)
-{
-    char *cp;
-    char *cpe;
-    int len;
-    
-    len = strlen(str);
-    for (cp = buf, cpe = buf+n-len; cp <= cpe; cp++) {
-        if (strncmp(cp, str, len) == 0)
-            return cp;
-    }
-    return NULL;
-}
-
 char *strncasestr(char *buf, char *str, int n)
 {
     char *cp;
