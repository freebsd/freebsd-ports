--- ./src/General/Web.hs.orig	2011-01-26 12:16:52.000000000 +0100
+++ ./src/General/Web.hs	2011-03-13 06:06:29.688516885 +0100
@@ -15,7 +15,7 @@
 
 import General.System
 import General.Base
-import Network.Wai
+import Network.Wai hiding(statusOK)
 import Blaze.ByteString.Builder(toLazyByteString)
 import Data.Enumerator.List(consume)
 import qualified Data.ByteString.Lazy.Char8 as LBS
