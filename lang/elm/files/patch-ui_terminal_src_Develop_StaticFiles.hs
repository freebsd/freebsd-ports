--- ui/terminal/src/Develop/StaticFiles.hs.orig	2018-08-20 13:41:41 UTC
+++ ui/terminal/src/Develop/StaticFiles.hs
@@ -11,7 +11,7 @@ module Develop.StaticFiles
 
 import Prelude hiding (lookup)
 import qualified Data.ByteString as BS
-import Data.FileEmbed (bsToExp)
+import Data.FileEmbed (bsToExp, embedFile)
 import qualified Data.HashMap.Strict as HM
 import Language.Haskell.TH (runIO)
 import System.FilePath ((</>))
@@ -89,7 +89,7 @@ sansFontPath =
 
 elm :: BS.ByteString
 elm =
-  $(bsToExp =<< runIO Build.compile)
+  $(embedFile "elm_all-packages")
 
 
 
