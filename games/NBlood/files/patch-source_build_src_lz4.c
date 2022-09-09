--- source/build/src/lz4.c.orig	2022-08-31 13:24:58 UTC
+++ source/build/src/lz4.c
@@ -114,7 +114,7 @@
 #endif
 
 #define LZ4_STATIC_LINKING_ONLY  /* LZ4_DISTANCE_MAX */
-#include "lz4.h"
+#include "my_lz4.h"
 /* see also "memory routines" below */
 
 
