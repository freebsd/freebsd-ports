--- ./Utility/Yesod.hs.orig	2013-07-09 22:04:16.000000000 +0200
+++ ./Utility/Yesod.hs	2013-07-16 12:02:57.000000000 +0200
@@ -31,7 +31,7 @@
 #ifndef __ANDROID__
 import Yesod.Default.Util
 import Language.Haskell.TH.Syntax (Q, Exp)
-#if MIN_VERSION_yesod_default(1,1,0)
+#if MIN_VERSION_yesod(1,2,0)
 import Data.Default (def)
 import Text.Hamlet hiding (Html)
 #endif
@@ -39,7 +39,7 @@
 
 #ifndef __ANDROID__
 widgetFile :: String -> Q Exp
-#if ! MIN_VERSION_yesod_default(1,1,0)
+#if ! MIN_VERSION_yesod(1,2,0)
 widgetFile = widgetFileNoReload
 #else
 widgetFile = widgetFileNoReload $ def
