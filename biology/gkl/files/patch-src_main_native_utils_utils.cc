--- src/main/native/utils/utils.cc.orig	2024-08-04 16:26:45 UTC
+++ src/main/native/utils/utils.cc
@@ -31,6 +31,10 @@
   #include <omp.h>
 #endif
 
+#ifdef __FreeBSD__
+  #include <omp.h>
+#endif
+
 #include "utils.h"
 #include <avx.h>
 
