--- Include/pyport.h.orig	2014-10-12 09:03:52.000000000 +0200
+++ Include/pyport.h	2016-04-03 19:26:20.938539000 +0200
@@ -686,7 +686,9 @@
 
 #ifdef __FreeBSD__
 #include <osreldate.h>
-#if __FreeBSD_version > 500039
+#if (__FreeBSD_version >= 500040 && __FreeBSD_version < 602113) || \
+    (__FreeBSD_version >= 700000 && __FreeBSD_version < 700054) || \
+    (__FreeBSD_version >= 800000 && __FreeBSD_version < 800001)
 # define _PY_PORT_CTYPE_UTF8_ISSUE
 #endif
 #endif
