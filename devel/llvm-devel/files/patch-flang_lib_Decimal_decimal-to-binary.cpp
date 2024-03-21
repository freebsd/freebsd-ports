--- flang/lib/Decimal/decimal-to-binary.cpp.orig
+++ flang/lib/Decimal/decimal-to-binary.cpp
@@ -16,6 +16,8 @@
 #include <ctype.h>
 #include <utility>
 
+#undef HUGE
+
 namespace Fortran::decimal {
 
 template <int PREC, int LOG10RADIX>
