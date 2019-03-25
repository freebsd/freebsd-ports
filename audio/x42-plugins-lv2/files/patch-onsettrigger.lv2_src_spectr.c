--- onsettrigger.lv2/src/spectr.c.orig
+++ onsettrigger.lv2/src/spectr.c
@@ -30,10 +30,17 @@
 # define csqrt(XX) std::sqrt(XX)
 # define creal(XX) std::real(XX)
 # define cimag(XX) std::imag(XX)
-# define _I ((complex_t)(1i))
-  #ifdef __cpp_lib_complex_udls
+
+# ifdef __cpp_lib_complex_udls
     using namespace std::literals::complex_literals;
-  #endif
+# endif
+
+# if defined __clang_major__ && __clang_major__ > 4
+#  define _I (std::complex<double>(0.0,1.0))
+# else
+#  define _I ((complex_t)(1i))
+# endif
+
   typedef std::complex<double> complex_t;
 #else
 # include <complex.h>
