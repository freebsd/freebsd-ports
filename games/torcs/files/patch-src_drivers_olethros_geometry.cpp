--- src/drivers/olethros/geometry.cpp.orig	2018-10-25 14:35:19 UTC
+++ src/drivers/olethros/geometry.cpp
@@ -370,7 +370,7 @@ void EstimateSphere (std::vector<Vector> P, Parametric
 				}
 				delta_total += delta;
 			}
-			if (isnan(r)) {
+			if (std::isnan(r)) {
 				for (i=0; i<d; i++) {
 					center[i] =  ((*(sphere->C))[i] - mean[i]) / scale;
 				}
