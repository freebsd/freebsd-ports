--- ./hsparser/HsLexer.lhs.orig	2004-05-18 01:40:34.000000000 +0200
+++ ./hsparser/HsLexer.lhs	2012-05-13 11:20:41.000000000 +0200
@@ -19,7 +19,7 @@
 import HsParseUtils
 import HsSyn(SrcLoc(..))
 
-import Char
+import Char hiding (isSymbol)
 import Ratio
 import Numeric
 \end{code}
