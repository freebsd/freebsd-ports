--- lazpaint/ugraph.pas.orig	2026-08-18 19:05:41 UTC
+++ lazpaint/ugraph.pas
@@ -1206,7 +1206,7 @@ begin
   w := FramePenWidth*ACanvasScale/10 / 2 + 1;
   rF := EmptyRectF;
   for pt in APoints do
-    rF := rF.Union(RectF(pt + PointF(0.5, 0.5) - PointF(w, w),
+    rF := rF.Union(BGRABitmapTypes.RectF(pt + PointF(0.5, 0.5) - PointF(w, w),
       pt + PointF(0.5, 0.5) + PointF(w, w)));
   result := rect(floor(rF.Left), floor(rF.Top),
     ceil(rF.Right), ceil(rF.Bottom));
