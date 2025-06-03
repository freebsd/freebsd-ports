--- lazpaint/ugraph.pas	2025-06-03 00:14:12.239399000 -0700
+++ lazpaint/ugraph.pas	2025-06-03 00:14:45.095187000 -0700
@@ -1206,7 +1206,7 @@
   w := FramePenWidth*ACanvasScale/10 / 2 + 1;
   rF := EmptyRectF;
   for pt in APoints do
-    rF := rF.Union(RectF(pt + PointF(0.5, 0.5) - PointF(w, w),
+    rF := rF.Union(BGRABitmapTypes.RectF(pt + PointF(0.5, 0.5) - PointF(w, w),
       pt + PointF(0.5, 0.5) + PointF(w, w)));
   result := rect(floor(rF.Left), floor(rF.Top),
     ceil(rF.Right), ceil(rF.Bottom));
