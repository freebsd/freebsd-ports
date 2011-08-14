--- ./src/FRP/Reactive/Internal/Future.hs.orig	2010-07-28 18:48:55.000000000 +0200
+++ ./src/FRP/Reactive/Internal/Future.hs	2011-07-16 11:01:46.000000000 +0200
@@ -23,7 +23,8 @@
 
 import Control.Applicative (Applicative(..))
 
-import Control.Comonad (Copointed,Comonad)
+import Control.Comonad
+import Data.Copointed
 
 import Test.QuickCheck
 
@@ -44,7 +45,7 @@
 -- time\/value pair.  Particularly useful with time types that have
 -- non-flat structure.
 newtype FutureG t a = Future { unFuture :: (Time t, a) }
-  deriving (Functor, Applicative, Monad, Copointed, Comonad {-, Show-}
+  deriving (Functor, Applicative, Monad, Extend, Copointed, Comonad {-, Show-}
            , Arbitrary, CoArbitrary)
 
 isNeverF :: (Bounded t, Eq t) => FutureG t t1 -> Bool
