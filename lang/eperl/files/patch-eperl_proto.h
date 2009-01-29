--- ./eperl_proto.h.orig	1998-07-10 03:52:24.000000000 -0400
+++ ./eperl_proto.h	2009-01-29 13:27:30.000000000 -0500
@@ -35,6 +35,8 @@
 #ifndef EPERL_PROTO_H
 #define EPERL_PROTO_H 1
 
+#include "eperl_getopt.h"
+
 /*_BEGIN_PROTO_*/
 
 /* eperl_main.c */
@@ -79,7 +81,7 @@
 extern char *ePerl_Efwrite(char *cpBuf, int nBuf, int cNum, char *cpOut);
 extern char *ePerl_Cfwrite(char *cpBuf, int nBuf, int cNum, char *cpOut);
 extern char *strnchr(char *buf, char chr, int n);
-extern char *strnstr(char *buf, char *str, int n);
+extern char *ePerl_strnstr(char *buf, char *str, int n);
 extern char *strncasestr(char *buf, char *str, int n);
 extern char *strndup(char *buf, int n);
 extern char *ePerl_Bristled2Plain(char *cpBuf);
