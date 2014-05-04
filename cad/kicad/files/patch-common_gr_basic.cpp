--- common/gr_basic.cpp.orig	2013-03-09 21:07:56.000000000 +0100
+++ common/gr_basic.cpp	2014-05-01 18:03:48.000000000 +0200
@@ -1390,7 +1390,7 @@
     }
 
     // A clip box exists: clip and draw the polygon.
-    static vector<wxPoint> clippedPolygon;
+    static std::vector<wxPoint> clippedPolygon;
     static pointVector     inputPolygon, outputPolygon;
 
     inputPolygon.clear();
