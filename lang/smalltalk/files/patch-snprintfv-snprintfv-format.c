--- snprintfv/snprintfv/format.c.orig	2013-03-23 20:56:26.000000000 +0100
+++ snprintfv/snprintfv/format.c	2013-04-29 23:02:07.000000000 +0200
@@ -55,7 +55,7 @@
 #   define isinfl(x) isnanl ((x) - (x))
 #  endif
 #  ifndef HAVE_MODFL
-static snv_long_double modfl (long double x, long double *exp);
+snv_long_double modfl (long double x, long double *exp);
 #  endif
 #  ifndef HAVE_COPYSIGNL
 static snv_long_double copysignl (long double x, long double y);
@@ -1098,7 +1098,7 @@ printf_string (STREAM *stream, struct pr
 
 #if !defined NO_FLOAT_PRINTING && defined HAVE_LONG_DOUBLE
 # ifndef HAVE_MODFL
-static long double modfl (long double x, long double *exp)
+long double modfl (long double x, long double *exp)
 {
   /* To compute the integer part of a positive integer (in this case
      abs(X)), sum a big enough integer to the absolute value, so that
