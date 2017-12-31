--- libguile/numbers.c.orig	2016-12-15 00:03:33 UTC
+++ libguile/numbers.c
@@ -45,7 +45,11 @@
 #  include <config.h>
 #endif
 
+/* With old GCC, do not override _Static_assert: it conflicts with
+   #include <complex.h> below. */
+#if defined(__clang__) || (__GNUC__ * 10 + __GNUC_MINOR__ >= 46)
 #include <verify.h>
+#endif
 #include <assert.h>
 
 #include <math.h>
@@ -183,7 +187,7 @@ static double atanh (double x) { return 0.5 * log ((1 
 
 
 #if defined (GUILE_I)
-#if defined HAVE_COMPLEX_DOUBLE
+#if defined HAVE_COMPLEX_DOUBLE && (HAVE_CLOG || HAVE_CLOG10 || HAVE_CEXP || HAVE_USABLE_CSQRT) && defined (SCM_COMPLEX_VALUE)
 
 /* For an SCM object Z which is a complex number (ie. satisfies
    SCM_COMPLEXP), return its value as a C level "complex double". */
