--- flang/include/flang/Runtime/time-intrinsic.h.orig
+++ flang/include/flang/Runtime/time-intrinsic.h
@@ -13,6 +13,7 @@
 #define FORTRAN_RUNTIME_TIME_INTRINSIC_H_
 
 #include "flang/Runtime/entry-names.h"
+#include <cstddef>
 #include <cinttypes>
 
 namespace Fortran::runtime {
