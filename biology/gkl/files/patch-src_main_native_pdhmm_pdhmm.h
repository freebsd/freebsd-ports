--- src/main/native/pdhmm/pdhmm.h.orig	2024-08-04 16:31:53 UTC
+++ src/main/native/pdhmm/pdhmm.h
@@ -27,6 +27,9 @@
 #ifdef linux
 #include <omp.h>
 #endif
+#ifdef __FreeBSD__
+#include <omp.h>
+#endif
 
 inline INT_TYPE roundDownToNearestMultipleOf(INT_TYPE val, INT_TYPE mul) { return (val / mul) * mul; }
 
