--- runtime/flang/cdexp.c.orig	2017-05-17 00:40:01 UTC
+++ runtime/flang/cdexp.c
@@ -22,7 +22,8 @@ __mth_i_cdexp(dcmplx_t *dcmplx, double r
 {
   double x, y, z;
   x = exp(real);
-  sincos(imag, &z, &y);
+  z = sin(imag);
+  y = cos(imag);
   y *= x;
   z *= x;
   d_dummy(y, z); /* should leave y & z in appropriate
