--- src/coord.h.orig	Sat Jan 17 17:26:46 2004
+++ src/coord.h	Sat Jan 17 17:26:59 2004
@@ -319,7 +319,7 @@
 };
 
 
-inline double distance(Coord3<double> &a, Coord3<double> &b)
+inline double dist(Coord3<double> &a, Coord3<double> &b)
 {
 	Coord3<double> tmp;
 	tmp = a - b;
