--- src/hyperbolic_motion.c.orig	Tue Jul  5 11:09:22 2005
+++ src/hyperbolic_motion.c	Sat Feb 18 02:17:12 2006
@@ -69,12 +69,12 @@
                 F = Z1 * G1;
                 Q3 = Q3 + F;
                 if (Z > 100 || fabs(F) > 10000)
-                        return nan("0");
+                        return strtod("NAN(0)", NULL);
                 if (fabs(F) > PREC)
                         goto next_z;
                 L++;
                 if (L > 100)
-                        return nan("0");
+                        return strtod("NAN(0)", NULL);
                 do
                 {
                         S1 = S;
