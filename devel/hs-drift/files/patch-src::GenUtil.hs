--- src/GenUtil.hs.orig	Thu Dec  2 09:16:02 2004
+++ src/GenUtil.hs	Thu Dec  2 09:16:33 2004
@@ -85,7 +85,7 @@
 import Monad
 import qualified IO
 import qualified System
-import Random(StdGen, newStdGen, randomR)
+import Random(StdGen, newStdGen, Random(randomR))
 import Time
 
 {-# SPECIALIZE snub :: [String] -> [String] #-}
