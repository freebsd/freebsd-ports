--- GUI/SaveAs.hs.orig	2001-09-09 01:46:40 UTC
+++ GUI/SaveAs.hs
@@ -27,7 +27,7 @@ saveAs :: HECs -> ViewParameters -> Double -> DrawingA
 
 saveAs :: HECs -> ViewParameters -> Double -> DrawingArea
        -> (Int, Int, Render ())
-saveAs hecs params' @ViewParameters{xScaleAreaHeight, width,
+saveAs hecs params'@ViewParameters{xScaleAreaHeight, width,
                                     height = oldHeight {-, histogramHeight-}}
        yScaleAreaWidth yScaleArea =
   let histTotalHeight = histXScaleHeight -- + histogramHeight
