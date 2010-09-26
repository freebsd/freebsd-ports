
FreeBSD does not have LOGIN_NAME_MAX, but it has MAXLOGNAME instead,
so use it as much as possible. Rewrite utmpx support.

--- tnftpd.h.orig	2009-11-07 10:59:09.000000000 +0100
+++ tnftpd.h	2009-11-07 10:59:09.000000000 +0100
@@ -119,6 +119,8 @@
 #endif
 #if defined(HAVE_UTMP_H)
 # include <utmp.h>
+#else
+# include <utmpx.h>
 #endif
 
 #if defined(HAVE_POLL)
@@ -561,8 +563,12 @@
 #define TM_YEAR_BASE	1900
 
 #if !defined(LOGIN_NAME_MAX)
+#if defined(MAXLOGNAME)
+# define LOGIN_NAME_MAX MAXLOGNAME
+#else
 # define LOGIN_NAME_MAX (9)
 #endif
+#endif
 
 #if !defined(_POSIX_LOGIN_NAME_MAX)
 # define _POSIX_LOGIN_NAME_MAX LOGIN_NAME_MAX
