--- src/Language/PureScript/Publish.hs.orig	2019-11-02 17:39:14 UTC
+++ src/Language/PureScript/Publish.hs
@@ -19,7 +19,7 @@ module Language.PureScript.Publish
   , getModules
   ) where
 
-import Protolude hiding (stdin)
+import Protolude hiding (stdin, lines)
 
 import Control.Arrow ((***))
 import Control.Category ((>>>))
@@ -36,7 +36,7 @@ import Data.Time.Clock (UTCTime)
 import Data.Time.Clock.POSIX (posixSecondsToUTCTime)
 import Data.Version
 import qualified Distribution.SPDX as SPDX
-import qualified Distribution.Parsec.Class as CabalParsec
+import qualified Distribution.Parsec as CabalParsec
 
 import System.Directory (doesFileExist)
 import System.FilePath.Glob (globDir1)
