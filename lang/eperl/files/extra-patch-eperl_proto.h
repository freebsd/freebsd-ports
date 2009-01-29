--- eperl_proto.h.orig	2009-01-29 16:05:55.000000000 -0500
+++ eperl_proto.h	2009-01-29 16:06:01.000000000 -0500
@@ -83,7 +83,6 @@
 extern char *strnchr(char *buf, char chr, int n);
 extern char *ePerl_ePerl_strnstr(char *buf, char *str, int n);
 extern char *strncasestr(char *buf, char *str, int n);
-extern char *strndup(char *buf, int n);
 extern char *ePerl_Bristled2Plain(char *cpBuf);
 
 /* eperl_pp.c */
