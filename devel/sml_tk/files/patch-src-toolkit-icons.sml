--- ./src/toolkit/icons.sml.orig	Fri Mar 30 23:39:44 2001
+++ src/toolkit/icons.sml	Sun Jan 13 11:03:51 2008
@@ -95,8 +95,8 @@
     fun getIconData (dir, file) = 
 	let val i = openFile(joinDirFile{dir=dir,
 					 file=dataFileNm file})
-            val w = StringUtil.toInt (TextIO.inputLine i)
-	    val h = StringUtil.toInt (TextIO.inputLine i)
+            val w = StringUtil.toInt (valOf (TextIO.inputLine i))
+	    val h = StringUtil.toInt (valOf (TextIO.inputLine i))
 	    val _ = TextIO.closeIn i
         in  (w, h)
 	end
