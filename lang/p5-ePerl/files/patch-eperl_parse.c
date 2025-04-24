--- eperl_parse.c.orig	1998-07-10 07:50:48 UTC
+++ eperl_parse.c
@@ -298,6 +298,7 @@ char *strnchr(char *buf, char chr, int n)
     return NULL;
 }
 
+#ifdef NOTDEF
 char *strnstr(char *buf, char *str, int n)
 {
     char *cp;
@@ -311,6 +312,7 @@ char *strnstr(char *buf, char *str, int n)
     }
     return NULL;
 }
+#endif
 
 char *strncasestr(char *buf, char *str, int n)
 {
@@ -326,6 +328,9 @@ char *strncasestr(char *buf, char *str, int n)
     return NULL;
 }
 
+#if defined(__FreeBSD__)  
+#include <osreldate.h>  
+#if __FreeBSD_version <= 800057 && __FreeBSD_version > 800000 || __FreeBSD_version <= 701100  
 char *strndup(char *buf, int n)
 {
     char *cp;
@@ -334,7 +339,8 @@ char *strndup(char *buf, int n)
     strncpy(cp, buf, n);
     return cp;
 }
-
+#endif
+#endif
 
 /*
 **  convert buffer from bristled format to plain format
