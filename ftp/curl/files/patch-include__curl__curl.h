Description: Include <sys/select.h> for fd_set on earlier versions of FreeBSD
Bug-FreeBSD: http://www.freebsd.org/cgi/query-pr.cgi?pr=141459
Forwarded: http://sourceforge.net/tracker/?func=detail&aid=2916915&group_id=976&atid=100976
Author: Renato Botelho <garga@FreeBSD.org>,
	Peter Pentchev <roam@ringlet.net>
Last-Update: 2009-12-18

--- a/include/curl/curl.h
+++ b/include/curl/curl.h
@@ -55,6 +55,11 @@
 #include <stdio.h>
 #include <limits.h>
 
+#if defined(__FreeBSD__)
+/* Needed to check FreeBSD version */
+#include <osreldate.h>
+#endif
+
 /* The include stuff here below is mainly for time_t! */
 #include <sys/types.h>
 #include <time.h>
@@ -74,7 +79,7 @@
    require it! */
 #if defined(_AIX) || defined(__NOVELL_LIBC__) || defined(__NetBSD__) || \
     defined(__minix) || defined(__SYMBIAN32__) || defined(__INTEGRITY) || \
-    defined(ANDROID)
+    defined(ANDROID) || (defined(__FreeBSD__) && __FreeBSD_version < 800000)
 #include <sys/select.h>
 #endif
 
