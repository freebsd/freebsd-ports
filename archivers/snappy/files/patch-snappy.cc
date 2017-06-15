--- snappy.cc.orig	2017-01-30 12:42:23 UTC
+++ snappy.cc
@@ -30,7 +30,7 @@
 #include "snappy-internal.h"
 #include "snappy-sinksource.h"
 
-#if defined(__x86_64__) || defined(_M_X64)
+#ifdef __SSE2__
 #include <emmintrin.h>
 #endif
 #include <stdio.h>
