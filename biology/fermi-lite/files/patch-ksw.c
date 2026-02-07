--- ksw.c.orig	2024-10-15 14:34:34 UTC
+++ ksw.c
@@ -25,7 +25,11 @@
 
 #include <stdlib.h>
 #include <stdint.h>
+#if defined(__arm__) || defined(__aarch64__)
+#include <sse2neon.h>
+#else
 #include <emmintrin.h>
+#endif
 #include "ksw.h"
 
 #ifdef __GNUC__
