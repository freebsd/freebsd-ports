--- src/haskell/SexpLex.hs.orig	1999-08-10 20:05:41.000000000 +0200
+++ src/haskell/SexpLex.hs	2007-10-01 14:24:55.000000000 +0200
@@ -1,5 +1,7 @@
 module SexpLex(Tok(..),scan,toString,)  where
 
+import Data.Char
+
 data Tok =
  LP | RP 
  | INT Int
