--- markdown/Cheapskate/ParserCombinators.hs.orig	2020-02-25 17:08:42 UTC
+++ markdown/Cheapskate/ParserCombinators.hs
@@ -1,3 +1,5 @@
+{-# LANGUAGE CPP #-}
+{- Patch from https://github.com/avh4/elm-format/pull/640/ -}
 module Cheapskate.ParserCombinators (
     Position(..)
   , Parser
@@ -37,6 +39,7 @@ import qualified Data.Text as T
 import Control.Monad
 import Control.Applicative
 import qualified Data.Set as Set
+import qualified Control.Monad.Fail as Fail
 
 data Position = Position { line :: Int, column :: Int }
      deriving (Ord, Eq)
@@ -107,9 +110,14 @@ instance Alternative Parser where
   {-# INLINE empty #-}
   {-# INLINE (<|>) #-}
 
+instance Fail.MonadFail Parser where
+  fail e = Parser $ \st -> Left $ ParseError (position st) e
+
 instance Monad Parser where
   return x = Parser $ \st -> Right (st, x)
-  fail e = Parser $ \st -> Left $ ParseError (position st) e
+#if !MIN_VERSION_base(4,13,0)
+  fail = Fail.fail
+#endif
   p >>= g = Parser $ \st ->
     case evalParser p st of
          Left e        -> Left e
