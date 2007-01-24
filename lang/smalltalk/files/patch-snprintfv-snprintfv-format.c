--- snprintfv/snprintfv/format.c.orig	Thu Jan 18 11:46:33 2007
+++ snprintfv/snprintfv/format.c	Thu Jan 18 11:51:54 2007
@@ -54,7 +54,7 @@
 #   define isinfl(x) isnanl ((x) - (x))
 #  endif
 #  ifndef HAVE_MODFL
-static snv_long_double modfl (long double x, long double *exp);
+snv_long_double modfl (long double x, long double *exp);
 #  endif
 #  ifndef HAVE_COPYSIGNL
 static snv_long_double copysignl (long double x, long double y);
@@ -1097,7 +1097,7 @@
 
 #if !defined NO_FLOAT_PRINTING && defined HAVE_LONG_DOUBLE
 # ifndef HAVE_MODFL
-static long double modfl (long double x, long double *exp)
+long double modfl (long double x, long double *exp)
 {
   /* To compute the integer part of a positive integer (in this case
      abs(X)), sum a big enough integer to the absolute value, so that
