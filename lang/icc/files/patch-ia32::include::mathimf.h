--- ia32/include/mathimf.h.orig	Fri Jan 10 18:15:48 2003
+++ ia32/include/mathimf.h	Fri Jan 10 18:36:16 2003
@@ -36,7 +36,7 @@
 # error "<mathimf.h> is incompatible with system <math.h>!"
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <math.h>  /* utilize GNU math header */
 # if defined(finite)
 #  undef finite
@@ -62,7 +62,7 @@
 #if defined(_DLL) && (defined(_WIN32) || defined(_WIN64))   /* Windows DLL */
 # define _LIBIMF_PUBAPI __declspec(dllimport) __cdecl
 # define _LIBIMF_PUBVAR __declspec(dllimport)
-#elif defined(__linux__)                          /* Linux */
+#elif defined(__linux__) || defined(__FreeBSD__)  /* Linux || FreeBSD */
 # define _LIBIMF_PUBAPI /* do not change this line! */
 # define _LIBIMF_PUBVAR
 #else                                             /* Windows static */
@@ -84,7 +84,7 @@
 # define _LIBIMF_FCOMPLEX _LIBIMF_FLOAT _Complex
 #endif
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 /*-- Real functions --*/
 
@@ -102,13 +102,13 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI tanf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI tanl (_LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI cot  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI cotf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI cotl (_LIBIMF_XDOUBLE __x);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI acos  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI acosf (_LIBIMF_FLOAT __x);
@@ -126,13 +126,13 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI atan2f (_LIBIMF_FLOAT __y, _LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI atan2l (_LIBIMF_XDOUBLE __y, _LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_VOID     _LIBIMF_PUBAPI sincos (_LIBIMF_DOUBLE __x, _LIBIMF_DOUBLE *__psin, _LIBIMF_DOUBLE *__pcos);
 _LIBIMF_EXT _LIBIMF_VOID     _LIBIMF_PUBAPI sincosf (_LIBIMF_FLOAT __x, _LIBIMF_FLOAT *__psin, _LIBIMF_FLOAT *__pcos);
 _LIBIMF_EXT _LIBIMF_VOID     _LIBIMF_PUBAPI sincosl (_LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE *__psin, _LIBIMF_XDOUBLE *__pcos);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 /* Exponential functions */
 
@@ -140,7 +140,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI expf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI expl (_LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI exp2  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI exp2f (_LIBIMF_FLOAT __x);
@@ -150,7 +150,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI exp10f (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI exp10l (_LIBIMF_XDOUBLE __x);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI expm1  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI expm1f (_LIBIMF_FLOAT __x);
@@ -172,13 +172,13 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI scalbnf (_LIBIMF_FLOAT __x, _LIBIMF_INT __n);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI scalbnl (_LIBIMF_XDOUBLE __x, _LIBIMF_INT __n);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI scalbln  (_LIBIMF_DOUBLE __x, _LIBIMF_LONGINT __n);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI scalblnf (_LIBIMF_FLOAT __x, _LIBIMF_LONGINT __n);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI scalblnl (_LIBIMF_XDOUBLE __x, _LIBIMF_LONGINT __n);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 /* Hyperbolic functions */
 
@@ -206,13 +206,13 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI atanhf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI atanhl (_LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_VOID     _LIBIMF_PUBAPI sinhcosh (_LIBIMF_DOUBLE __x, _LIBIMF_DOUBLE *__psinh, _LIBIMF_DOUBLE *__pcosh);
 _LIBIMF_EXT _LIBIMF_VOID     _LIBIMF_PUBAPI sinhcoshf (_LIBIMF_FLOAT __x, _LIBIMF_FLOAT *__psinh, _LIBIMF_FLOAT *__pcosh);
 _LIBIMF_EXT _LIBIMF_VOID     _LIBIMF_PUBAPI sinhcoshl (_LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE *__psinh, _LIBIMF_XDOUBLE *__pcosh);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 /* Logarithmic functions */
 
@@ -220,13 +220,13 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI logf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI logl (_LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI log2  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI log2f (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI log2l (_LIBIMF_XDOUBLE __x);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI log10  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI log10f (_LIBIMF_FLOAT __x);
@@ -254,13 +254,13 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI sqrtf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI sqrtl (_LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI invsqrt  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI invsqrtf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI invsqrtl (_LIBIMF_XDOUBLE __x);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI cbrt  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI cbrtf (_LIBIMF_FLOAT __x);
@@ -280,13 +280,13 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI remainderf (_LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI remainderl (_LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE __y);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI remquo  (_LIBIMF_DOUBLE __x, _LIBIMF_DOUBLE __y, _LIBIMF_INT *__quo);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI remquof (_LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y, _LIBIMF_INT *__quo);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI remquol (_LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE __y, _LIBIMF_INT *__quo);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI fmod  (_LIBIMF_DOUBLE __x, _LIBIMF_DOUBLE __y);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI fmodf (_LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y);
@@ -298,13 +298,13 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI rintf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI rintl (_LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI round  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI roundf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI roundl (_LIBIMF_XDOUBLE __x);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI ceil  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI ceilf (_LIBIMF_FLOAT __x);
@@ -314,19 +314,19 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI floorf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI floorl (_LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI trunc  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI truncf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI truncl (_LIBIMF_XDOUBLE __x);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI modf  (_LIBIMF_DOUBLE __x, _LIBIMF_DOUBLE *__iptr);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI modff (_LIBIMF_FLOAT __x, _LIBIMF_FLOAT *__iptr);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI modfl (_LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE *__iptr);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_LONGINT  _LIBIMF_PUBAPI lrint  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_LONGINT  _LIBIMF_PUBAPI lrintf (_LIBIMF_FLOAT __x);
@@ -348,7 +348,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI nearbyintf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI nearbyintl (_LIBIMF_XDOUBLE __x);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 /* Special functions */
 
@@ -385,7 +385,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI lgammaf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI lgammal (_LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI tgamma  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI tgammaf (_LIBIMF_FLOAT __x);
@@ -394,12 +394,12 @@
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI gamma_r  (_LIBIMF_DOUBLE __x, _LIBIMF_INT *__signgam);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI gammaf_r (_LIBIMF_FLOAT __x, _LIBIMF_INT *__signgam);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI lgamma_r  (_LIBIMF_DOUBLE __x, _LIBIMF_INT *__signgam);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI lgammaf_r (_LIBIMF_FLOAT __x, _LIBIMF_INT *__signgam);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 /* Special (financial) functions */
 
@@ -457,7 +457,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI fminf (_LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI fminl (_LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE __y);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI copysign  (_LIBIMF_DOUBLE __x, _LIBIMF_DOUBLE __y);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI copysignf (_LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y);
@@ -467,25 +467,25 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI nextafterf (_LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI nextafterl (_LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE __y);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI nexttoward  (_LIBIMF_DOUBLE __x, _LIBIMF_XDOUBLE __y);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI nexttowardf (_LIBIMF_FLOAT __x, _LIBIMF_XDOUBLE __y);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI nexttowardl (_LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE __y);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI significand  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI significandf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI significandl (_LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI fma  (_LIBIMF_DOUBLE __x, _LIBIMF_DOUBLE __y, _LIBIMF_DOUBLE __z);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI fmaf (_LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y, _LIBIMF_FLOAT __z);
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI fmal (_LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE __y, _LIBIMF_XDOUBLE __z);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_INT      _LIBIMF_PUBAPI finite  (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_INT      _LIBIMF_PUBAPI finitef (_LIBIMF_FLOAT __x);
@@ -495,7 +495,7 @@
 _LIBIMF_EXT _LIBIMF_INT      _LIBIMF_PUBAPI isnanf (_LIBIMF_FLOAT __x);
 _LIBIMF_EXT _LIBIMF_INT      _LIBIMF_PUBAPI isnanl (_LIBIMF_XDOUBLE __x);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 /*-- Complex functions --*/
 
@@ -505,7 +505,7 @@
 
 /* Complex trigonometric functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI ccos  (_LIBIMF_DCOMPLEX __z);
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI ccosf (_LIBIMF_FCOMPLEX __z);
@@ -528,24 +528,24 @@
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI carg  (_LIBIMF_DCOMPLEX __z);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI cargf (_LIBIMF_FCOMPLEX __z);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI cis (_LIBIMF_DOUBLE __x);
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI cisf (_LIBIMF_FLOAT __x);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 /* Complex exponential functions */
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI cexp  (_LIBIMF_DCOMPLEX __z);
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI cexpf (_LIBIMF_FCOMPLEX __z);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI cexp10  (_LIBIMF_DCOMPLEX __z);
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI cexp10f (_LIBIMF_FCOMPLEX __z);
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI ccosh  (_LIBIMF_DCOMPLEX __z);
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI ccoshf (_LIBIMF_FCOMPLEX __z);
@@ -570,7 +570,7 @@
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI clog  (_LIBIMF_DCOMPLEX __z);
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI clogf (_LIBIMF_FCOMPLEX __z);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI clog2  (_LIBIMF_DCOMPLEX __z);
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI clog2f (_LIBIMF_FCOMPLEX __z);
@@ -580,7 +580,7 @@
 
 /* Complex power/root/abs functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI cpow  (_LIBIMF_DCOMPLEX __z, _LIBIMF_DCOMPLEX __c);
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI cpowf (_LIBIMF_FCOMPLEX __z, _LIBIMF_FCOMPLEX __c);
@@ -591,9 +591,9 @@
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI cabs  (_LIBIMF_DCOMPLEX __z);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI cabsf (_LIBIMF_FCOMPLEX __z);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 /* Other complex functions */
 
@@ -609,7 +609,7 @@
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI creal  (_LIBIMF_DCOMPLEX __z);
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI crealf (_LIBIMF_FCOMPLEX __z);
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 #endif  /*__IMFCOMPLEXON*/
 
@@ -632,7 +632,7 @@
     _LIBIMF_DOUBLE  retval;
 } ___exception;
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 # if defined(__cplusplus)
 #  define __exception ____exception   /* map 'struct __exception'  to 'struct ____exception'  */
 # else     /*__cplusplus*/
@@ -661,9 +661,9 @@
     _LIBIMF_XDOUBLE  retval;
 } ___exceptionl;
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 _LIBIMF_EXT _LIBIMF_INT _LIBIMF_PUBAPI matherr  (struct ____exception  *__e);
-#endif /*!__linux__*/
+#endif /*!__linux__ && !__FreeBSD__*/
 _LIBIMF_EXT _LIBIMF_INT _LIBIMF_PUBAPI matherrf (struct ____exceptionf *__e);
 _LIBIMF_EXT _LIBIMF_INT _LIBIMF_PUBAPI matherrl (struct ____exceptionl *__e);
 
@@ -694,9 +694,9 @@
 
 /* Standard conformance support */
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 typedef _LIB_VERSION_TYPE _LIB_VERSIONIMF_TYPE;
-#else  /*__linux__*/
+#else  /*__linux__ || __FreeBSD__*/
 typedef enum ___LIB_VERSIONIMF_TYPE {
      _IEEE_ = -1    /* IEEE-like behavior    */
     ,_SVID_         /* SysV, Rel. 4 behavior */
@@ -704,7 +704,7 @@
     ,_POSIX_        /* Posix                 */
     ,_ISOC_         /* ISO C9X               */
 } _LIB_VERSIONIMF_TYPE;
-#endif /*__linux__*/
+#endif /*__linux__ || __FreeBSD__*/
 
 _LIBIMF_EXT _LIB_VERSIONIMF_TYPE _LIBIMF_PUBVAR _LIB_VERSIONIMF;
 
