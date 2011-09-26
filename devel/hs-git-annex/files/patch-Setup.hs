--- ./Setup.hs.orig	2011-07-02 23:11:40.000000000 +0200
+++ ./Setup.hs	2011-07-08 23:11:28.256484379 +0200
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