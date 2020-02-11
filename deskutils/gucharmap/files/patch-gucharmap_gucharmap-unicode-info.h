--- gucharmap/gucharmap-unicode-info.h.orig	2018-06-17 14:45:00 UTC
+++ gucharmap/gucharmap-unicode-info.h
@@ -50,7 +50,10 @@ typedef enum {
   GUCHARMAP_UNICODE_VERSION_9_0,
   GUCHARMAP_UNICODE_VERSION_10_0,
   GUCHARMAP_UNICODE_VERSION_11_0,
-  GUCHARMAP_UNICODE_VERSION_LATEST = GUCHARMAP_UNICODE_VERSION_11_0 /* private, will move forward with each revision */
+  GUCHARMAP_UNICODE_VERSION_12_0,
+  GUCHARMAP_UNICODE_VERSION_12_1,
+  GUCHARMAP_UNICODE_VERSION_13_0,
+  GUCHARMAP_UNICODE_VERSION_LATEST = GUCHARMAP_UNICODE_VERSION_12_1 /* private, will move forward with each revision */
 } GucharmapUnicodeVersion;
 
 /* return values are read-only */
