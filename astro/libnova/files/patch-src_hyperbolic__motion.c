--- src/hyperbolic_motion.c.orig	2011-07-28 11:02:50 UTC
+++ src/hyperbolic_motion.c
@@ -70,12 +70,12 @@ next_z:
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
