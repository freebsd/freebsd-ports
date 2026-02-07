--- src/main/native/pdhmm/pdhmm-implementation.h.orig	2025-08-23 18:25:35 UTC
+++ src/main/native/pdhmm/pdhmm-implementation.h
@@ -31,7 +31,7 @@
 #include "avx512_impl.h"
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <omp.h>
 #endif
 
