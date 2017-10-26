--- runtime/flang/cdexp.c.orig	2017-10-19 11:03:03 UTC
+++ runtime/flang/cdexp.c
@@ -24,7 +24,8 @@ ZMPLXFUNC_Z(__mth_i_cdexp)
   ZMPLXARGS_Z;
   double x, y, z;
   x = exp(real);
-  __mth_dsincos(imag, &z, &y);
+  z = sin(imag);
+  y = cos(imag);
   y *= x;
   z *= x;
   ZRETURN_D_D(y, z); /* should leave y & z in appropriate
