--- libguile/numbers.c.orig	2010-12-13 17:25:01 UTC
+++ libguile/numbers.c
@@ -160,7 +160,7 @@ xisnan (double x)
 }
 
 #if defined (GUILE_I)
-#if HAVE_COMPLEX_DOUBLE
+#if HAVE_COMPLEX_DOUBLE && (HAVE_CLOG || HAVE_CLOG10 || HAVE_CEXP || HAVE_USABLE_CSQRT) && defined (SCM_COMPLEX_VALUE)
 
 /* For an SCM object Z which is a complex number (ie. satisfies
    SCM_COMPLEXP), return its value as a C level "complex double". */
