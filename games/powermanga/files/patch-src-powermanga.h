--- src/powermanga.h.orig	2012-08-26 19:44:26.000000000 +0400
+++ src/powermanga.h	2013-08-23 23:19:06.028234150 +0400
@@ -149,6 +149,7 @@
 
 #ifdef PNG_EXPORT_ENABLE
 #include <png.h>
+#include <zlib.h> /* for Z_BEST_COMPRESSION */
 #endif
 
 #if !defined(_WIN32_WCE)
