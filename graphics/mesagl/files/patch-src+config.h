--- src/config.h.orig	2008-07-15 00:16:29.000000000 -0500
+++ src/config.h	2008-07-15 00:19:17.000000000 -0500
@@ -118,8 +118,8 @@
 #define MAX_TEXTURE_UNITS 8
 
 /* Maximum viewport/image size: */
-#define MAX_WIDTH 2048
-#define MAX_HEIGHT 2048
+#define MAX_WIDTH 4096
+#define MAX_HEIGHT 4096
 
 /* Maxmimum size for CVA.  May be overridden by the drivers.  */
 #define MAX_ARRAY_LOCK_SIZE 3000
@@ -162,7 +162,7 @@
  * rasterizer code.
  */
 #ifndef DEFAULT_SOFTWARE_DEPTH_BITS
-#define DEFAULT_SOFTWARE_DEPTH_BITS 16
+#define DEFAULT_SOFTWARE_DEPTH_BITS 24
 #endif
 #if DEFAULT_SOFTWARE_DEPTH_BITS <= 16
 #define DEFAULT_SOFTWARE_DEPTH_TYPE GLushort
