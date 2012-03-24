--- common/mpmath_c.c.orig	2012-03-10 17:28:37.000000000 -0500
+++ common/mpmath_c.c	2012-03-10 17:34:32.000000000 -0500
@@ -220,7 +220,7 @@
       if(t.x < -690)
          e2x = 0.0;
       else
-         e2x = expl(t.x);
+         e2x = exp(t.x);
 #ifdef XFRACT
       if (isnan(e2x) || isinf(e2x))
          e2x = 1.0;
