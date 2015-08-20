--- src/ParseLib2.hs.orig	2013-11-11 15:22:00 UTC
+++ src/ParseLib2.hs
@@ -32,6 +32,7 @@ module ParseLib2
     opt, skipUntil, skipUntilOff,skipUntilParse,skipNest) where
 
 import Data.Char
+import Control.Applicative (Alternative, empty, (<|>))
 import Control.Monad
 
 infixr 5 +++
@@ -62,6 +63,14 @@ instance MonadPlus Parser where
    -- mplus            :: Parser a -> Parser a -> Parser a
    (P p) `mplus` (P q)    = P (\pos inp -> (p pos inp ++ q pos inp))
 
+instance Applicative Parser where
+   pure  = return
+   (<*>) = ap
+
+instance Alternative Parser where
+   empty = mzero
+   (<|>) = mplus
+
 -- bits which donn't fit into Haskell's type classes just yet :-(
 
 env :: Parser Pos
