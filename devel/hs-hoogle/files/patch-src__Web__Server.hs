--- ./src/Web/Server.hs.orig	2011-01-26 12:16:52.000000000 +0100
+++ ./src/Web/Server.hs	2011-03-13 06:06:43.636623976 +0100
@@ -10,7 +10,7 @@
 import General.System
 import Control.Concurrent
 
-import Network.Wai
+import Network.Wai hiding(statusOK)
 import Network.Wai.Handler.Warp
 import qualified Data.ByteString.Lazy.Char8 as LBS
 import qualified Data.ByteString.Char8 as BS
