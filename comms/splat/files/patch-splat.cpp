--- splat.cpp.orig	2018-01-18 17:04:01 UTC
+++ splat.cpp
@@ -567,7 +567,7 @@ double ElevationAngle(struct site source, struct site 
 	   (downtilt), as referenced to a normal to the center of
 	   the earth. */
 	   
-	register double a, b, dx;
+	double a, b, dx;
 
 	a=GetElevation(destination)+destination.alt+earthradius;
 	b=GetElevation(source)+source.alt+earthradius;
@@ -2727,7 +2727,7 @@ void PlotPath(struct site source, struct site destinat
 
 	char block;
 	int x, y;
-	register double cos_xmtr_angle, cos_test_angle, test_alt;
+	double cos_xmtr_angle, cos_test_angle, test_alt;
 	double distance, rx_alt, tx_alt;
 
 	ReadPath(source,destination);
