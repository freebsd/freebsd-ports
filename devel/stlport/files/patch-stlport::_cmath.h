--- stlport/stl/_cmath.h.orig	Wed Jul 24 03:31:26 2002
+++ stlport/stl/_cmath.h	Wed Jul 24 03:32:38 2002
@@ -100,7 +100,7 @@
 #  define _STLP_DO_TAN(_Tp)   _STLP_VENDOR_CSTD::tan
 #  define _STLP_DO_TANH(_Tp)  _STLP_VENDOR_CSTD::tanh
 #  define _STLP_DO_EXP(_Tp)   _STLP_VENDOR_CSTD::exp
-# if defined (__GNUC__) || defined ( __IBMCPP__ ) || defined (__SUNPRO_CC)
+# if defined (__GNUC__) || defined ( __IBMCPP__ ) || defined (__SUNPRO_CC) || defined (__ICC)
 #  define _STLP_DO_HYPOT(_Tp) ::hypot
 # else
 #  define _STLP_DO_HYPOT(_Tp) _STLP_VENDOR_CSTD::hypot
