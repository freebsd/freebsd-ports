--- server/asobj/flash/geom/Point_as.cpp.orig	2008-05-14 14:38:44.000000000 +0400
+++ server/asobj/flash/geom/Point_as.cpp	2008-05-17 02:22:11.737384190 +0400
@@ -193,9 +193,9 @@
 		ptr->get_member(NSV::PROP_X, &xval);
 		ptr->get_member(NSV::PROP_Y, &yval);
 		double x = xval.to_number();
-		if ( ! isfinite(x) ) return as_value(NAN);
+		if ( ! std::isfinite(x) ) return as_value(NAN);
 		double y = yval.to_number();
-		if ( ! isfinite(y) ) return as_value(NAN);
+		if ( ! std::isfinite(y) ) return as_value(NAN);
 
 		double l = sqrt(x*x+y*y);
 		return as_value(l);
