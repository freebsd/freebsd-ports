--- eperl_proto.h.orig	Fri Jul 10 09:52:24 1998
+++ eperl_proto.h	Wed May 30 19:13:42 2007
@@ -36,6 +36,7 @@
 #define EPERL_PROTO_H 1
 
 /*_BEGIN_PROTO_*/
+#include "eperl_getopt.h"
 
 /* eperl_main.c */
 extern int mode;
@@ -79,7 +80,7 @@
 extern char *ePerl_Efwrite(char *cpBuf, int nBuf, int cNum, char *cpOut);
 extern char *ePerl_Cfwrite(char *cpBuf, int nBuf, int cNum, char *cpOut);
 extern char *strnchr(char *buf, char chr, int n);
-extern char *strnstr(char *buf, char *str, int n);
+/*extern char *strnstr(char *buf, char *str, int n);*/
 extern char *strncasestr(char *buf, char *str, int n);
 extern char *strndup(char *buf, int n);
 extern char *ePerl_Bristled2Plain(char *cpBuf);
