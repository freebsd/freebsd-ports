--- Data/PSQueue.hs.orig        2018-04-19 15:27:45 UTC
+++ Data/PSQueue.hs
@@ -62,7 +62,7 @@ module Data.PSQueue
     , foldl
 ) where
 
-import Prelude hiding (lookup,null,foldl,foldr)
+import Prelude hiding (lookup,null,foldl,foldr,(<>))
 import qualified Prelude as P
 
 {-
