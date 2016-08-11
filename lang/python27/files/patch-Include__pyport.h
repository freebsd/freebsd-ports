--- Include/pyport.h.orig	2015-12-05 20:46:54.000000000 +0100
+++ Include/pyport.h	2016-04-03 17:14:53.047412000 +0200
@@ -702,7 +702,9 @@
 
 #ifdef __FreeBSD__
 #include <osreldate.h>
-#if __FreeBSD_version > 500039
+#if (__FreeBSD_version >= 500040 && __FreeBSD_version < 602113) || \
+    (__FreeBSD_version >= 700000 && __FreeBSD_version < 700054) || \
+    (__FreeBSD_version >= 800000 && __FreeBSD_version < 800001)
 # define _PY_PORT_CTYPE_UTF8_ISSUE
 #endif
 #endif
