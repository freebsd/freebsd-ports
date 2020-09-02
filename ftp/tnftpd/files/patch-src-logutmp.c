FreeBSD does not have header file util.h, fortunately it is not needed.
Add header file time.h for time(). Rewrite utmpx support.

--- src/logutmp.c.orig	2013-03-21 01:02:40 UTC
+++ src/logutmp.c
@@ -71,13 +71,15 @@ __RCSID(" NetBSD: logutmp.c,v 1.12 2011/09/16 16:13:17
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <time.h>
 #include <ttyent.h>
 #include <unistd.h>
+#ifdef SUPPORT_UTMP
 #include <utmp.h>
+#endif
 #ifdef SUPPORT_UTMPX
 #include <utmpx.h>
 #endif
-#include <util.h>
 
 #endif /* !defined(HAVE_TNFTPD_H) */
 
@@ -161,7 +163,7 @@ ftpd_logout(const char *line)
 }
 #endif /* SUPPORT_UTMP */
 
-#ifdef SUPPORT_UTMPX
+#if 0
 /*
  * special version of loginx which updates utmpx only.
  */
