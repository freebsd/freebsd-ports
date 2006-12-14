
FreeBSD does not have LOGIN_NAME_MAX, but it has MAXLOGNAME instead,
so use it as much as possible.

--- tnftpd.h.orig	Wed Dec 13 14:38:43 2006
+++ tnftpd.h	Wed Dec 13 14:39:24 2006
@@ -479,7 +479,11 @@
 #define TM_YEAR_BASE	1900
 
 #if ! defined(LOGIN_NAME_MAX)
+#if defined(MAXLOGNAME)
+# define LOGIN_NAME_MAX MAXLOGNAME
+#else
 # define LOGIN_NAME_MAX (9)
+#endif
 #endif
 
 #if ! defined(_POSIX_LOGIN_NAME_MAX)
