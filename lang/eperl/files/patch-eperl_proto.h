
$FreeBSD$

--- eperl_proto.h	2001/12/19 14:37:46	1.1
+++ eperl_proto.h	2001/12/19 14:39:24
@@ -79,7 +79,6 @@
 extern char *ePerl_Efwrite(char *cpBuf, int nBuf, int cNum, char *cpOut);
 extern char *ePerl_Cfwrite(char *cpBuf, int nBuf, int cNum, char *cpOut);
 extern char *strnchr(char *buf, char chr, int n);
-extern char *strnstr(char *buf, char *str, int n);
 extern char *strncasestr(char *buf, char *str, int n);
 extern char *strndup(char *buf, int n);
 extern char *ePerl_Bristled2Plain(char *cpBuf);
