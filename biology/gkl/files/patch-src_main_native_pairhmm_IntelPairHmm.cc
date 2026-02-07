--- src/main/native/pairhmm/IntelPairHmm.cc.orig	2024-08-04 16:29:20 UTC
+++ src/main/native/pairhmm/IntelPairHmm.cc
@@ -24,6 +24,9 @@
 #ifdef linux
 #include <omp.h>
 #endif
+#ifdef __FreeBSD__
+#include <omp.h>
+#endif
 #include <vector>
 #include <math.h>
 #include <debug.h>
