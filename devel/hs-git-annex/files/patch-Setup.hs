--- ./Setup.hs.orig	2011-11-22 20:21:05.000000000 +0100
+++ ./Setup.hs	2011-12-03 14:33:37.000000000 +0100
@@ -9,9 +9,9 @@
 }
 
 makeSources _ _ = do
-	system "make sources"
+	system "gmake sources manuals"
 	return (Nothing, [])
 
 makeClean _ _ _ _ = do
-	system "make clean"
+	system "gmake clean"
 	return ()
