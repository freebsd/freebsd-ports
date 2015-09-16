--- GPU/GLES/TextureScaler.cpp.orig	2015-02-26 20:05:06 UTC
+++ GPU/GLES/TextureScaler.cpp
@@ -34,8 +34,8 @@
 #include <stdlib.h>
 #include <math.h>
 
-#if _M_SSE >= 0x402
-#include <nmmintrin.h>
+#if _M_SSE >= 0x401
+#include <smmintrin.h>
 #endif
 
 // Report the time and throughput for each larger scaling operation in the log
