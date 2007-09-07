--- tools/lib/latex/text-to-latex.sml.orig	Tue Jul 24 14:14:47 2007
+++ tools/lib/latex/text-to-latex.sml	Tue Jul 24 14:15:03 2007
@@ -538,7 +538,7 @@
 		      trans(last, arg, colAlign)
 		  | transCell (last, Flt.TD arg, colAlign) =
 		      trans(last, arg, colAlign)
-		fun doCells ([cell], [colAlign]) =
+		fun doCells ([cell], colAlign::_) =
 		      ignore (transCell(true, cell, colAlign))
 		  | doCells (cell::r1, colAlign::r2) = let
 		      val nCols = transCell(false, cell, colAlign)
