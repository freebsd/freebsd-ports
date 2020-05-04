--- src/Language/PureScript/Docs/Types.hs.orig	2019-11-02 17:39:14 UTC
+++ src/Language/PureScript/Docs/Types.hs
@@ -6,7 +6,7 @@ module Language.PureScript.Docs.Types
   )
   where
 
-import Protolude hiding (to, from)
+import Protolude hiding (to, from, unlines)
 import Prelude (String, unlines, lookup)
 
 import GHC.Generics (Generic)
