--- src/osgEarthDrivers/fastdxt/libdxt.cpp.orig	2018-11-12 18:17:36 UTC
+++ src/osgEarthDrivers/fastdxt/libdxt.cpp
@@ -24,7 +24,7 @@
 
 #include "libdxt.h"
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || (__FreeBSD__)
 #define memalign(x,y) malloc((y))
 #else
 #include <malloc.h>
@@ -92,4 +92,4 @@ int CompressDXT(const byte *in, byte *ou
   // Join all the threads
   nbbytes = job.nbb;
   return nbbytes;
-}
\ No newline at end of file
+}
