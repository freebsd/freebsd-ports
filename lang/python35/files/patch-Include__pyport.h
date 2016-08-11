--- Include/pyport.h.orig	2015-12-07 02:39:07.000000000 +0100
+++ Include/pyport.h	2016-04-03 19:31:36.801717000 +0200
@@ -677,7 +677,9 @@
 
 #ifdef __FreeBSD__
 #include <osreldate.h>
-#if __FreeBSD_version > 500039
+#if (__FreeBSD_version >= 500040 && __FreeBSD_version < 602113) || \
+    (__FreeBSD_version >= 700000 && __FreeBSD_version < 700054) || \
+    (__FreeBSD_version >= 800000 && __FreeBSD_version < 800001)
 # define _PY_PORT_CTYPE_UTF8_ISSUE
 #endif
 #endif
