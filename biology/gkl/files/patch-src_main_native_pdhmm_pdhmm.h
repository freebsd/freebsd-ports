--- src/main/native/pdhmm/pdhmm.h.orig	2025-07-07 07:42:12 UTC
+++ src/main/native/pdhmm/pdhmm.h
@@ -27,6 +27,9 @@
 #ifdef linux
 #include <omp.h>
 #endif
+#ifdef __FreeBSD__
+#include <omp.h>
+#endif
 
 inline INT_TYPE CONCAT(roundDownToNearestMultipleOf_, SIMD_ENGINE)(INT_TYPE val, INT_TYPE mul) { return (val / mul) * mul; }
 
