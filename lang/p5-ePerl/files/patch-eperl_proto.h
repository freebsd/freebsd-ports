--- eperl_proto.h.orig	Thu Nov 21 21:26:44 2002
+++ eperl_proto.h	Thu Nov 21 21:26:50 2002
@@ -79,7 +79,7 @@
 extern char *ePerl_Efwrite(char *cpBuf, int nBuf, int cNum, char *cpOut);
 extern char *ePerl_Cfwrite(char *cpBuf, int nBuf, int cNum, char *cpOut);
 extern char *strnchr(char *buf, char chr, int n);
-extern char *strnstr(char *buf, char *str, int n);
+/*extern char *strnstr(char *buf, char *str, int n);*/
 extern char *strncasestr(char *buf, char *str, int n);
 extern char *strndup(char *buf, int n);
 extern char *ePerl_Bristled2Plain(char *cpBuf);
