--- src/osgEarthDrivers/fastdxt/util.h.orig	2018-11-18 08:00:00 UTC
+++ src/osgEarthDrivers/fastdxt/util.h
@@ -64,7 +64,7 @@ void aFree(void* const p);
 float drand48(void);
 #endif
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define memalign(x,y) malloc((y))
 #else
 #include <malloc.h>
