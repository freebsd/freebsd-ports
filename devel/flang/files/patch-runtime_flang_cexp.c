--- runtime/flang/cexp.c.orig	2017-05-17 00:40:01 UTC
+++ runtime/flang/cexp.c
@@ -22,7 +22,8 @@ __mth_i_cexp(cmplx_t *cmplx, float real,
 {
   float x, y, z;
   x = exp(real);
-  sincosf(imag, &z, &y);
+  z = sinf(imag);
+  y = cosf(imag);
   y *= x;
   z *= x;
   r_dummy(y, z); /* should leave y & z in appropriate
