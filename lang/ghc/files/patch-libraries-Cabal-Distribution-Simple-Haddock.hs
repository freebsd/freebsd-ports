--- libraries/Cabal/Distribution/Simple/Haddock.hs.orig	2007-12-10 18:18:23.000000000 +0000
+++ libraries/Cabal/Distribution/Simple/Haddock.hs	2008-02-20 15:02:53.000000000 +0000
@@ -122,7 +122,7 @@
                      then "--hoogle"
                      else "--html"
     let Just version = programVersion confHaddock
-    let have_src_hyperlink_flags = version >= Version [0,8] [] && version < Version [2,0] []
+    let have_src_hyperlink_flags = version >= Version [0,8] []
         isVersion2               = version >= Version [2,0] []
 
     let mockFlags
