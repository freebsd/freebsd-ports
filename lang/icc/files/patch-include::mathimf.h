--- include/mathimf.h.orig	Sun Dec 12 17:56:24 2004
+++ include/mathimf.h	Sun Dec 12 18:02:12 2004
@@ -40,7 +40,7 @@
 # endif
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <math.h>  /* utilize GNU math header */
 # if defined(fpclassify)
 #  undef fpclassify
@@ -262,7 +262,7 @@
 
 /* Radian argument trigonometric functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI acos( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI acosf( _LIBIMF_FLOAT __x );
@@ -292,7 +292,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI tanf( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI tanl( _LIBIMF_XDOUBLE __x );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI cot( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI cotf( _LIBIMF_FLOAT __x );
@@ -346,7 +346,7 @@
 
 /* Hyperbolic functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI acosh( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI acoshf( _LIBIMF_FLOAT __x );
@@ -372,7 +372,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI tanhf( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI tanhl( _LIBIMF_XDOUBLE __x );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_VOID     _LIBIMF_PUBAPI sinhcosh( _LIBIMF_DOUBLE __x, _LIBIMF_DOUBLE *__psinh, _LIBIMF_DOUBLE *__pcosh );
 _LIBIMF_EXT _LIBIMF_VOID     _LIBIMF_PUBAPI sinhcoshf( _LIBIMF_FLOAT __x, _LIBIMF_FLOAT *__psinh, _LIBIMF_FLOAT *__pcosh );
@@ -380,13 +380,13 @@
 
 /* Exponential functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI exp( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI expf( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI expl( _LIBIMF_XDOUBLE __x );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI exp2( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI exp2f( _LIBIMF_FLOAT __x );
@@ -396,7 +396,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI exp10f( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI exp10l( _LIBIMF_XDOUBLE __x );
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI expm1( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI expm1f( _LIBIMF_FLOAT __x );
@@ -418,7 +418,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI scalbnf( _LIBIMF_FLOAT __x, _LIBIMF_INT __n );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI scalbnl( _LIBIMF_XDOUBLE __x, _LIBIMF_INT __n );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI scalbln( _LIBIMF_DOUBLE __x, _LIBIMF_LONGINT __n );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI scalblnf( _LIBIMF_FLOAT __x, _LIBIMF_LONGINT __n );
@@ -426,19 +426,19 @@
 
 /* Logarithmic functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI log( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI logf( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI logl( _LIBIMF_XDOUBLE __x );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI log2( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI log2f( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI log2l( _LIBIMF_XDOUBLE __x );
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI log10( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI log10f( _LIBIMF_FLOAT __x );
@@ -460,11 +460,11 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI modff( _LIBIMF_FLOAT __x, _LIBIMF_FLOAT *__iptr );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI modfl( _LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE *__iptr );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 /* Power/root/abs functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI cbrt( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI cbrtf( _LIBIMF_FLOAT __x );
@@ -486,7 +486,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI sqrtf( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI sqrtl( _LIBIMF_XDOUBLE __x );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI invsqrt( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI invsqrtf( _LIBIMF_FLOAT __x );
@@ -494,7 +494,7 @@
 
 /* Error and gamma functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI erf( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI erff( _LIBIMF_FLOAT __x );
@@ -516,7 +516,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI gammaf( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI gammal( _LIBIMF_XDOUBLE __x );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI gamma_r( _LIBIMF_DOUBLE __x, _LIBIMF_INT *__signgam );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI gammaf_r( _LIBIMF_FLOAT __x, _LIBIMF_INT *__signgam );
@@ -528,7 +528,7 @@
 
 /* Nearest integer functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI ceil( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI ceilf( _LIBIMF_FLOAT __x );
@@ -538,19 +538,19 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI floorf( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI floorl( _LIBIMF_XDOUBLE __x );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI nearbyint( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI nearbyintf( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI nearbyintl( _LIBIMF_XDOUBLE __x );
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI rint( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI rintf( _LIBIMF_FLOAT __x );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI rintl( _LIBIMF_XDOUBLE __x );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_LONGINT  _LIBIMF_PUBAPI lrint( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_LONGINT  _LIBIMF_PUBAPI lrintf( _LIBIMF_FLOAT __x );
@@ -578,7 +578,7 @@
 
 /* Remainder functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI fmod( _LIBIMF_DOUBLE __x, _LIBIMF_DOUBLE __y );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI fmodf( _LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y );
@@ -588,7 +588,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI remainderf( _LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI remainderl( _LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE __y );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI remquo( _LIBIMF_DOUBLE __x, _LIBIMF_DOUBLE __y, _LIBIMF_INT *__quo );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI remquof( _LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y, _LIBIMF_INT *__quo );
@@ -596,7 +596,7 @@
 
 /* Manipulation functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI significand( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI significandf( _LIBIMF_FLOAT __x );
@@ -610,7 +610,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI nextafterf( _LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI nextafterl( _LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE __y );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI nexttoward( _LIBIMF_DOUBLE __x, _LIBIMF_XDOUBLE __y );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI nexttowardf( _LIBIMF_FLOAT __x, _LIBIMF_XDOUBLE __y );
@@ -646,7 +646,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI compoundf( _LIBIMF_FLOAT __x, _LIBIMF_FLOAT __y );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI compoundl( _LIBIMF_XDOUBLE __x, _LIBIMF_XDOUBLE __y );
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI j0( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI j0f( _LIBIMF_FLOAT __x );
@@ -666,7 +666,7 @@
 _LIBIMF_EXT _LIBIMF_DOUBLE   _LIBIMF_PUBAPI yn( _LIBIMF_INT __n, _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI ynf( _LIBIMF_INT __n, _LIBIMF_FLOAT __x );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 #if (__IMFLONGDOUBLE == 64)	/* MS compatibility */
 # define acosdl       acosd
@@ -784,7 +784,7 @@
 
 /* Complex trigonometric functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI ccos( _LIBIMF_DCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI ccosf( _LIBIMF_FCOMPLEX __z );
@@ -814,7 +814,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI cargf( _LIBIMF_FCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI cargl( _LIBIMF_XCOMPLEX __z );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI cis( _LIBIMF_DOUBLE __x );
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI cisf( _LIBIMF_FLOAT __x );
@@ -826,13 +826,13 @@
 
 /* Complex exponential functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI cexp( _LIBIMF_DCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI cexpf( _LIBIMF_FCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_XCOMPLEX _LIBIMF_PUBAPI cexpl( _LIBIMF_XCOMPLEX __z );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI cexp2( _LIBIMF_DCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI cexp2f( _LIBIMF_FCOMPLEX __z );
@@ -842,7 +842,7 @@
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI cexp10f( _LIBIMF_FCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_XCOMPLEX _LIBIMF_PUBAPI cexp10l( _LIBIMF_XCOMPLEX __z );
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI ccosh( _LIBIMF_DCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI ccoshf( _LIBIMF_FCOMPLEX __z );
@@ -868,17 +868,17 @@
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI catanhf( _LIBIMF_FCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_XCOMPLEX _LIBIMF_PUBAPI catanhl( _LIBIMF_XCOMPLEX __z );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 /* Complex logarithmic functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI clog( _LIBIMF_DCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI clogf( _LIBIMF_FCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_XCOMPLEX _LIBIMF_PUBAPI clogl( _LIBIMF_XCOMPLEX __z );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI clog2( _LIBIMF_DCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI clog2f( _LIBIMF_FCOMPLEX __z );
@@ -890,7 +890,7 @@
 
 /* Complex power/root/abs functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI cpow( _LIBIMF_DCOMPLEX __z, _LIBIMF_DCOMPLEX __c );
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI cpowf( _LIBIMF_FCOMPLEX __z, _LIBIMF_FCOMPLEX __c );
@@ -904,11 +904,11 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI cabsf( _LIBIMF_FCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI cabsl( _LIBIMF_XCOMPLEX __z );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 /* Other complex functions */
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 _LIBIMF_EXT _LIBIMF_DCOMPLEX _LIBIMF_PUBAPI conj( _LIBIMF_DCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_FCOMPLEX _LIBIMF_PUBAPI conjf( _LIBIMF_FCOMPLEX __z );
@@ -926,7 +926,7 @@
 _LIBIMF_EXT _LIBIMF_FLOAT    _LIBIMF_PUBAPI crealf( _LIBIMF_FCOMPLEX __z );
 _LIBIMF_EXT _LIBIMF_XDOUBLE  _LIBIMF_PUBAPI creall( _LIBIMF_XCOMPLEX __z );
 
-#endif  /*!__linux__*/
+#endif  /*!__linux__ && !__FreeBSD__*/
 
 #if (__IMFLONGDOUBLE == 64)	/* MS compatibility */
 # define cabsl   cabs
@@ -979,7 +979,7 @@
     _LIBIMF_DOUBLE  retval;
 } ___exception;
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 # if defined(__cplusplus)
 #  define __exception ____exception   /* map 'struct __exception'  to 'struct ____exception'  */
 # else     /*__cplusplus*/
@@ -1008,9 +1008,9 @@
     _LIBIMF_XDOUBLE  retval;
 } ___exceptionl;
 
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__FreeBSD__)
 _LIBIMF_EXT _LIBIMF_INT _LIBIMF_PUBAPI matherr( struct ____exception  *__e );
-#endif /*!__linux__*/
+#endif /*!__linux__ && !__FreeBSD__*/
 _LIBIMF_EXT _LIBIMF_INT _LIBIMF_PUBAPI matherrf( struct ____exceptionf *__e );
 _LIBIMF_EXT _LIBIMF_INT _LIBIMF_PUBAPI matherrl( struct ____exceptionl *__e );
 
