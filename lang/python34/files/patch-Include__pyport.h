--- Include/pyport.h.orig	2015-12-21 07:00:57.000000000 +0100
+++ Include/pyport.h	2016-04-03 19:29:17.797369000 +0200
@@ -680,7 +680,9 @@
 
 #ifdef __FreeBSD__
 #include <osreldate.h>
-#if __FreeBSD_version > 500039
+#if (__FreeBSD_version >= 500040 && __FreeBSD_version < 602113) || \
+    (__FreeBSD_version >= 700000 && __FreeBSD_version < 700054) || \
+    (__FreeBSD_version >= 800000 && __FreeBSD_version < 800001)
 # define _PY_PORT_CTYPE_UTF8_ISSUE
 #endif
 #endif
