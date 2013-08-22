--- FeLib/Source/bitmap.cpp.orig	2004-10-26 23:35:47.000000000 +0400
+++ FeLib/Source/bitmap.cpp	2013-05-30 22:23:14.349113259 +0400
@@ -873,12 +873,12 @@
   static const int PointY[] = { 0, -1, 0, 0, 1 };
   const int Times = Wide ? 5 : 1;
 
-  for(int c = 0; c < Times; ++c)
+  for(int t = 0; t < Times; ++t)
   {
-    const int X1 = OrigFromX + PointX[c];
-    const int Y1 = OrigFromY + PointY[c];
-    const int X2 = OrigToX + PointX[c];
-    const int Y2 = OrigToY + PointY[c];
+    const int X1 = OrigFromX + PointX[t];
+    const int Y1 = OrigFromY + PointY[t];
+    const int X2 = OrigToX + PointX[t];
+    const int Y2 = OrigToY + PointY[t];
     const int DeltaX = abs(X2 - X1);
     const int DeltaY = abs(Y2 - Y1);
     int x, c;
