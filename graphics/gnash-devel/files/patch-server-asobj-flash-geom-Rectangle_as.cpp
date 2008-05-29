--- server/asobj/flash/geom/Rectangle_as.cpp.orig	2008-05-14 14:38:44.000000000 +0400
+++ server/asobj/flash/geom/Rectangle_as.cpp	2008-05-17 02:22:29.328831706 +0400
@@ -241,10 +241,10 @@
 	if ( h.is_undefined() || h.is_null() ) return as_value(true);
 
 	double wn = w.to_number();
-	if ( ! isfinite(wn) || wn == 0 ) return as_value(true);
+	if ( ! std::isfinite(wn) || wn == 0 ) return as_value(true);
 
 	double hn = h.to_number();
-	if ( ! isfinite(hn) || hn == 0 ) return as_value(true);
+	if ( ! std::isfinite(hn) || hn == 0 ) return as_value(true);
 
 	log_debug("Width: %g, Height: %g", wn, hn);
 
