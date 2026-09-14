--- src/drivers/olethros/geometry.cpp.orig	2026-04-10 09:55:27 UTC
+++ src/drivers/olethros/geometry.cpp
@@ -371,7 +371,7 @@ void EstimateSphere (std::vector<Vector> P, Parametric
 				}
 				delta_total += delta;
 			}
-			if (isnan(r)) {
+			if (std::isnan(r)) {
 				for (i=0; i<d; i++) {
 					center[i] =  ((*(sphere->C))[i] - mean[i]) / scale;
 				}
