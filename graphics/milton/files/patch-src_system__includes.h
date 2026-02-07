--- src/system_includes.h.orig	2019-06-05 15:34:53 UTC
+++ src/system_includes.h
@@ -41,14 +41,12 @@
 #include <string.h>
 #include <inttypes.h>
 
-#include <xmmintrin.h>
-#include <emmintrin.h>
 
 #if defined(_WIN32)
 
 #include "gl.h"
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
 #include "gl.h"
 
