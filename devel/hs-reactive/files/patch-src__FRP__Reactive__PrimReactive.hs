--- ./src/FRP/Reactive/PrimReactive.hs.orig	2010-07-28 18:48:55.000000000 +0200
+++ ./src/FRP/Reactive/PrimReactive.hs	2011-07-16 11:19:19.000000000 +0200
@@ -63,6 +63,8 @@
 import Prelude hiding (zip,zipWith)
 
 import Data.Monoid
+import Data.Pointed
+import Data.Copointed
 import Control.Applicative
 import Control.Arrow (first)
 import Control.Monad
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
@@ -738,14 +730,14 @@
   -- Semantically: extract == extract . rat == (`rat` mempty) But mempty
   -- is the earliest time (since I'm using the Max monoid *), so here's a
   -- cheap alternative that also doesn't require Ord t:
-  extract (a `Stepper` _) = a
+  copoint (a `Stepper` _) = a
 
 -- extract r == extract (rat r) == rat r mempty
 
 -- * Moreover, mempty is the earliest time in the Sum monoid on
 -- non-negative values, for relative-time behaviors.
 
-instance Monoid t => Comonad (ReactiveG t) where
+instance Monoid t => Extend (ReactiveG t) where
   duplicate r@(_ `Stepper` Event u) =
     r `Stepper` Event (duplicate <$> u)
 
