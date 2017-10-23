--- runtime/flang/cdcos.c.orig	2017-10-23 04:19:13 UTC
+++ runtime/flang/cdcos.c
@@ -25,9 +25,8 @@ ZMPLXFUNC_Z(__mth_i_cdcos)
   x = cos(real) * cosh(imag);
   y = -sin(real) * sinh(imag);
   */
-  // x = cos(real);
-  // y = sin(real);
-  __mth_dsincos(real, &y, &x);
+  x = cos(real);
+  y = sin(real);
   x = x * cosh(imag);
   y = -y * sinh(imag);
   ZRETURN_D_D(x, y);
