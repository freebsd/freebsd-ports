--- libguile/numbers.c	2008-02-23 15:41:35.231371691 -0600
+++ libguile/numbers.c	2008-02-23 15:44:52.401368437 -0600
@@ -170,7 +170,7 @@
 #endif
 
 /* Convert a C "complex double" to an SCM value. */
-#if HAVE_COMPLEX_DOUBLE
+#if HAVE_COMPLEX_DOUBLE && (HAVE_CLOG || HAVE_CLOG10 || HAVE_CEXP || HAVE_USABLE_CSQRT) && defined (SCM_COMPLEX_VALUE)
 static SCM
 scm_from_complex_double (complex double z)
 {
