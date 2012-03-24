--- unix/fpu087.c.orig	2012-03-24 17:16:18.000000000 +0100
+++ unix/fpu087.c	2012-03-24 17:17:15.000000000 +0100
@@ -31,7 +31,7 @@
     if (isnan(*x) || isnan(*y) || isinf(*x) || isinf(*y))
       *atan = 1.0;
     else
-      *atan = (double)atan2l(*y,*x);
+      *atan = (double)atan2f((float)*y,(float)*x);
 }
 
 void FPUcplxmul(_CMPLX *x, _CMPLX *y, _CMPLX *z)
@@ -112,7 +112,7 @@
     if (isnan(xx) || isnan(xy) || isinf(xx) || isinf(xy))
       z->y = 1.0;
     else
-      z->y = (double)atan2l(xy,xx);
+      z->y = (double)atan2f((float)xy,(float)xx);
 }
 
 void FPUcplxexp387(_CMPLX *x, _CMPLX *z)
