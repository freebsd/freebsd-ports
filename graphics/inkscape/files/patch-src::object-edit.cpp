--- src/object-edit.cpp.orig	Fri Feb 18 02:09:25 2005
+++ src/object-edit.cpp	Fri Feb 18 02:25:08 2005
@@ -839,7 +839,7 @@
 			spiral->rad = rad_new;
 			spiral->t0 = pow (r0 / spiral->rad, 1/spiral->exp);
 		}
-		if (!std::isfinite(spiral->t0)) spiral->t0 = 0.0;
+		if (isinf(spiral->t0)) spiral->t0 = 0.0;
 		spiral->t0 = CLAMP (spiral->t0, 0.0, 0.999);	
 	}
 
