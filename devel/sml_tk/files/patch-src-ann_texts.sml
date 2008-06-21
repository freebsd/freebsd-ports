--- ./src/ann_texts.sml.orig	Fri Mar 30 23:38:57 2001
+++ src/ann_texts.sml	Sun Jan 13 11:03:51 2008
@@ -69,7 +69,7 @@
 	       if (StringUtil.isLinefeed thischar) 
 		   then (line+1, 0)
 	       else (line, char+1)
-	       val (rows, cols) = Substring.foldl cnt (1, 0) (Substring.all t)
+	       val (rows, cols) = Substring.foldl cnt (1, 0) (Substring.full t)
 	   in (Int.max(rows, 1), cols)
 	   end
 
