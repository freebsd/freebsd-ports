--- ./formats/f-sharp/FSharpTop.hs.orig	2010-09-15 16:26:38.000000000 +0200
+++ ./formats/f-sharp/FSharpTop.hs	2012-05-12 23:50:50.000000000 +0200
@@ -35,10 +35,9 @@
 import CFtoXML
 import GetCF
 import Utils
-
+import System.Exit
 import Char
 import Data.Maybe (fromMaybe,maybe)
-import System
 import Monad(when)
 
 -- naming conventions
