--- ./GUI/Timeline/Render.hs.orig	2011-12-07 01:21:24.000000000 +0100
+++ ./GUI/Timeline/Render.hs	2011-12-07 01:24:29.000000000 +0100
@@ -91,7 +91,7 @@
   region exposeRegion
   clip
   setSourceSurface surface 0 (-vadj_value)
-          -- ^^ this is where we adjust for the vertical scrollbar
+          -- this is where we adjust for the vertical scrollbar
   setOperator OperatorSource
   paint
   when (scaleValue params > 0) $ do
