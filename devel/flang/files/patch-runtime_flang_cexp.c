--- runtime/flang/cexp.c.orig	2017-10-19 11:03:03 UTC
+++ runtime/flang/cexp.c
@@ -22,7 +22,8 @@ CMPLXFUNC_C(__mth_i_cexp)
   CMPLXARGS_C;
   float x, y, z;
   x = EXPF(real);
-  __mth_sincos(imag, &z, &y);
+  z = sinf(imag);
+  y = cosf(imag);
   y *= x;
   z *= x;
   CRETURN_F_F(y, z); /* should leave y & z in appropriate
