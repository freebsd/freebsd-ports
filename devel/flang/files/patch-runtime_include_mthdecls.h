--- runtime/include/mthdecls.h.orig	2017-10-19 11:03:03 UTC
+++ runtime/include/mthdecls.h
@@ -536,19 +536,6 @@ double __mth_i_dbessel_y1(double arg);
 double __mth_i_dbessel_yn(int n, double arg);
 double __f90_dbessel_yn(int n1, int n, double d);
 
-#if	! defined (TARGET_X8664) && ! defined(LINUX8664)
-/*
- * See explanation below for rationale behind the two flavors of __mth_sincos.
- */
-static inline void __mth_sincos(float angle, float *s, float *c)
-        __attribute__((always_inline));
-static inline void __mth_dsincos(double angle, double *s, double *c)
-        __attribute__((always_inline));
-#else	/* ! defined (TARGET_X8664) && ! defined(LINUX8664) */
-void __mth_sincos(float, float *, float *);
-void __mth_dsincos(double, double *, double *);
-#endif	/* ! defined (TARGET_X8664) && ! defined(LINUX8664) */
-
 FLTDECL_C(__mth_i_cabs);
 CMPLXDECL_C(__mth_i_cacos);
 CMPLXDECL_C(__mth_i_casin);
@@ -657,6 +644,3 @@ extern complex double ctan(complex double);
  * have a version of __mth_sincos, even if it is not external available
  * during the build process.
  */
-
-#define	__mth_sincos(_a,_s,_c) sincosf(_a,_s,_c)
-#define	__mth_dsincos(_a,_s,_c) sincos(_a,_s,_c)
