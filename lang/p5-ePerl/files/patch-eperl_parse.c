--- eperl_parse.c.orig	Thu Nov 21 21:27:34 2002
+++ eperl_parse.c	Thu Nov 21 21:27:42 2002
@@ -298,6 +298,7 @@
     return NULL;
 }
 
+#ifdef NOTDEF
 char *strnstr(char *buf, char *str, int n)
 {
     char *cp;
@@ -311,6 +312,7 @@
     }
     return NULL;
 }
+#endif
 
 char *strncasestr(char *buf, char *str, int n)
 {
