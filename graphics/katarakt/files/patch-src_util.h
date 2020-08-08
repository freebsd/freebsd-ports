--- src/util.h.orig	2020-08-08 07:25:17 UTC
+++ src/util.h
@@ -7,11 +7,6 @@
 
 class QImage;
 
-
-#define POPPLER_VERSION ((POPPLER_VERSION_MAJOR << 16) | (POPPLER_VERSION_MINOR << 8) | (POPPLER_VERSION_MICRO))
-
-#define POPPLER_VERSION_CHECK(major,minor,micro) ((major << 16) | (minor << 8) | (micro))
-
 // rounds a float when afterwards cast to int
 // seems to fix the mismatch between calculated page height and actual image height
 #define ROUND(x) ((x) + 0.5f)
