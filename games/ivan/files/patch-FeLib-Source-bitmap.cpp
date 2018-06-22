--- FeLib/Source/bitmap.cpp.orig	2004-10-26 19:35:47 UTC
+++ FeLib/Source/bitmap.cpp
@@ -873,12 +873,12 @@ void bitmap::DrawLine(int OrigFromX, int
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
