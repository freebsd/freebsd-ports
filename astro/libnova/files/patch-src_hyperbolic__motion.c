--- src/hyperbolic_motion.c.orig	2015-03-03 11:16:58 UTC
+++ src/hyperbolic_motion.c
@@ -73,14 +73,14 @@ next_z:
 		Q3 = Q3 + F;
 
 		if (Z > 100 || fabs(F) > 10000)
-			return nan("0");
+			return strtod("NAN(0)", NULL);
 
 		if (fabs(F) > PREC)
 			goto next_z;
 
 		L++;
 		if (L > 100)
-			return nan("0");
+			return strtod("NAN(0)", NULL);
 
 		do {
 			S1 = S;
