--- flang-rt/lib/quadmath/complex-math.c.orig
+++ flang-rt/lib/quadmath/complex-math.c
@@ -7,6 +7,7 @@
  *===----------------------------------------------------------------------===*/
 
 #include "complex-math.h"
+#ifndef __aarch64__
 
 #if HAS_LDBL128 || HAS_FLOAT128
 
@@ -52,3 +53,4 @@
 }
 
 #endif // HAS_LDBL128 || HAS_FLOAT128
+#endif
