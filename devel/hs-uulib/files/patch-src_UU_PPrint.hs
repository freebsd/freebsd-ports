--- src/UU/PPrint.hs.orig       2018-04-11 18:54:44 UTC
+++ src/UU/PPrint.hs
@@ -60,7 +60,7 @@ module UU.PPrint
 import System.IO      (Handle,hPutStr,hPutChar,stdout)
 
 #if __GLASGOW_HASKELL__ >= 710
-import Prelude hiding ((<$>))
+import Prelude hiding ((<$>), (<>))
 #endif
 
 infixr 5 </>,<//>,<$>,<$$>
