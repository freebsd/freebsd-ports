--- src/imageformats/raw.cpp.orig	2025-09-08 08:12:54 UTC
+++ src/imageformats/raw.cpp
@@ -27,7 +27,7 @@
  * By defining RAW_IGNORE_BROKEN_STREAMS removes this protection, leaving
  * LibRaw in complete control of error handling (which is mostly absent).
  */
-// #define RAW_DISABLE_BROKEN_STREAM_PROTECTION
+#define RAW_DISABLE_BROKEN_STREAM_PROTECTION
 #endif
 
 #ifdef QT_DEBUG
