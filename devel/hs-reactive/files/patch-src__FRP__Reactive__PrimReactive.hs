--- ./src/FRP/Reactive/PrimReactive.hs.orig	2010-07-28 18:48:55.000000000 +0200
+++ ./src/FRP/Reactive/PrimReactive.hs	2012-10-04 23:37:49.000000000 +0200
@@ -63,6 +63,8 @@
 import Prelude hiding (zip,zipWith)
 
 import Data.Monoid
+import Data.Pointed
+import Data.Copointed
 import Control.Applicative
 import Control.Arrow (first)
 import Control.Monad
@@ -78,7 +80,7 @@
 
 import Control.Comonad
 
-import Test.QuickCheck
+import Test.QuickCheck hiding (once)
 import Test.QuickCheck.Instances
 import Test.QuickCheck.Checkers
 import Test.QuickCheck.Classes
@@ -708,17 +710,7 @@
 
 instance Copointed (EventG t) where
   -- E a -> F (R a) -> R a -> a
-  extract = extract . extract . eFuture
-
--- Here's the plan for 'duplicate':
--- 
---   E a -> F (R a) -> F (R (R a)) -> F (F (R (R a)))
---       -> F (R (F (R a))) -> E (F (R a)) -> E (E a)
-
-
-instance Monoid t => Comonad (EventG t) where
-  duplicate =
-    fmap Event . Event . fmap frTOrf . duplicate . fmap duplicate . eFuture
+  copoint = copoint . copoint . eFuture
 
 -- This frTOrf definition type-checks.  Is it what we want?
 frTOrf :: FutureG t (ReactiveG t a) -> ReactiveG t (FutureG t a)
@@ -738,7 +730,7 @@
   -- Semantically: extract == extract . rat == (`rat` mempty) But mempty
   -- is the earliest time (since I'm using the Max monoid *), so here's a
   -- cheap alternative that also doesn't require Ord t:
-  extract (a `Stepper` _) = a
+  copoint (a `Stepper` _) = a
 
 -- extract r == extract (rat r) == rat r mempty
 
@@ -872,13 +864,13 @@
 toListE_ = map futVal . toListE
 -}
 
-monotonicity :: (Show a, Arbitrary a, Arbitrary t
+monotonicity :: (Show a, Show t, Arbitrary a, Arbitrary t
                 ,Num t, Ord t, Bounded t, Ord t', Bounded t')
              => String -> (EventG t a -> EventG t' a')
              -> (String,Property)
 monotonicity n f = (n, property $ monotoneTest f)
 
-monotonicity2 :: (Show a, Show b, Arbitrary a, Arbitrary b, Arbitrary t
+monotonicity2 :: (Show a, Show b, Show t, Arbitrary a, Arbitrary b, Arbitrary t
                  ,Num t, Ord t, Bounded t, Ord t', Bounded t')
               => String -> (b -> EventG t a -> EventG t' a')
               -> (String,Property)
@@ -921,7 +913,7 @@
 isMonotoneR' :: (Ord t, Bounded t) => Time t -> ReactiveG t a -> Bool
 isMonotoneR' t (_ `Stepper` e) = isMonotoneE' t e
 
-simulEventOrder :: ( Arbitrary t, Num t, Ord t, Bounded t
+simulEventOrder :: ( Arbitrary t, Show t, Show t', Show t'', Show t''', Num t, Ord t, Bounded t
                    , Arbitrary t', Num t', Ord t', Bounded t'
                    , Num t'', Ord t'', Bounded t''
                    , Num t''', Ord t''', Bounded t''')
