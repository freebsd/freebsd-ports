--- ./formats/ocaml/OCamlTop.hs.orig	2010-09-15 16:26:38.000000000 +0200
+++ ./formats/ocaml/OCamlTop.hs	2012-05-13 12:04:23.291467169 +0200
@@ -37,7 +37,7 @@
 
 import Char
 import Data.Maybe (fromMaybe,maybe)
-import System
+import System.Exit
 import Monad(when)
 
 -- naming conventions
