--- tnftpd.h-orig	Wed Feb 26 19:16:13 2003
+++ tnftpd.h	Sun Aug  3 15:49:57 2003
@@ -404,6 +404,8 @@
 #define SECSPERDAY	86400
 #define TM_YEAR_BASE	1900
 
-#if ! defined(LOGIN_NAME_MAX)
+#if defined(MAXLOGNAME)
+# define LOGIN_NAME_MAX MAXLOGNAME
+#elif ! defined(LOGIN_NAME_MAX)
 # define LOGIN_NAME_MAX (9)
 #endif
