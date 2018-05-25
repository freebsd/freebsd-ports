--- c2hs/c/CPretty.hs.orig      2018-04-15 10:03:19 UTC
+++ c2hs/c/CPretty.hs
@@ -34,6 +34,8 @@ module CPretty (
   -- we are just providing instances to the class `Pretty'
 ) where
 
+import Prelude hiding ((<>))
+
 import Idents (Ident, identToLexeme)
 import Text.PrettyPrint.HughesPJ
