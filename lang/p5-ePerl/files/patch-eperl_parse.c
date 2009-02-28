--- eperl_parse.c.orig	2009-02-27 12:23:36.000000000 +0000
+++ eperl_parse.c	2009-02-27 12:25:38.000000000 +0000
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
@@ -326,6 +328,9 @@
     return NULL;
 }
 
+#if defined(__FreeBSD__)  
+#include <osreldate.h>  
+#if __FreeBSD_version <= 800057 && __FreeBSD_version > 800000 || __FreeBSD_version <= 701100  
 char *strndup(char *buf, int n)
 {
     char *cp;
@@ -334,7 +339,8 @@
     strncpy(cp, buf, n);
     return cp;
 }
-
+#endif
+#endif
 
 /*
 **  convert buffer from bristled format to plain format
