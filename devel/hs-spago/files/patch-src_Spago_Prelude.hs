--- src/Spago/Prelude.hs.orig	2020-04-15 16:39:52 UTC
+++ src/Spago/Prelude.hs
@@ -1,5 +1,5 @@
 module Spago.Prelude
-  ( 
+  (
   -- * Basic exports
     module X
   , Proxy(..)
@@ -12,7 +12,7 @@ module Spago.Prelude
   , headMay
   , lastMay
   , empty
-  
+
   -- * Logging, errors, printing, etc
   , Pretty
   , pretty
@@ -97,7 +97,7 @@ import           Data.Text.Prettyprint.Doc            
 import           Data.Text.IO.Utf8                     (readFile, writeFile)
 import           Dhall.Optics                          (transformMOf)
 import           Lens.Family                           ((^..))
-import           RIO                                   as X hiding (FilePath, first, force, second)
+import           RIO                                   as X hiding (FilePath, first, force, second, mapRIO)
 import           RIO.Orphans                           as X
 import           Safe                                  (headMay, lastMay)
 import           System.FilePath                       (isAbsolute, pathSeparator, (</>))
@@ -229,7 +229,7 @@ pretty = PrettyText.renderStrict
 --   or die trying
 findExecutableOrDie :: HasLogFunc env => String -> RIO env Text
 findExecutableOrDie cmd = do
-  Directory.findExecutable cmd >>= \case 
+  Directory.findExecutable cmd >>= \case
     Nothing -> die [ "Executable was not found in path: " <> displayShow cmd ]
     Just path -> pure $ Text.pack path
 
