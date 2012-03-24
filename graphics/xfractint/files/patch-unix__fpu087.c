--- unix/fpu087.c.orig	2012-03-10 17:28:49.000000000 -0500
+++ unix/fpu087.c	2012-03-10 17:36:40.000000000 -0500
@@ -86,8 +86,8 @@
     *Sinh = 1.0;
     *Cosh = 1.0;
   } else {
-    *Sinh = (double)sinhl(*Angle);
-    *Cosh = (double)coshl(*Angle);
+    *Sinh = (double)sinh(*Angle);
+    *Cosh = (double)cosh(*Angle);
   }
   if (isnan(*Sinh) || isinf(*Sinh))
     *Sinh = 1.0;
@@ -119,7 +119,7 @@
 {
     LDBL pwr,y;
     y = x->y;
-    pwr = expl(x->x);
+    pwr = exp(x->x);
     if (isnan(pwr) || isinf(pwr))
       pwr = 1.0;
     z->x = (double)(pwr*cosl(y));
