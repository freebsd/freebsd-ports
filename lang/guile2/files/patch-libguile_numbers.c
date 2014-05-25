--- libguile/numbers.c	2008-07-09 14:50:22.000000000 +0800
+++ libguile/numbers.c	2008-07-09 14:53:05.000000000 +0800
@@ -183,7 +183,7 @@
 
 
 #if defined (GUILE_I)
-#if defined HAVE_COMPLEX_DOUBLE
+#if defined HAVE_COMPLEX_DOUBLE && (HAVE_CLOG || HAVE_CLOG10 || HAVE_CEXP || HAVE_USABLE_CSQRT) && defined (SCM_COMPLEX_VALUE)
 
 /* For an SCM object Z which is a complex number (ie. satisfies
    SCM_COMPLEXP), return its value as a C level "complex double". */
