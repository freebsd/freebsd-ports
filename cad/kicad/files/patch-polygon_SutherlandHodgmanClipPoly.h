--- polygon/SutherlandHodgmanClipPoly.h.orig	2013-03-09 20:51:52.000000000 +0100
+++ polygon/SutherlandHodgmanClipPoly.h	2014-05-01 18:01:22.000000000 +0200
@@ -80,9 +80,9 @@
 
 #endif // _GDIPLUS_H
 
-typedef vector<PointF>                 pointVector;
-typedef vector<PointF>::iterator       pointIterator;
-typedef vector<PointF>::const_iterator cpointIterator;
+typedef std::__1::vector<PointF>                 pointVector;
+typedef std::__1::vector<PointF>::iterator       pointIterator;
+typedef std::__1::vector<PointF>::const_iterator cpointIterator;
 
 class SutherlandHodgman
 {
