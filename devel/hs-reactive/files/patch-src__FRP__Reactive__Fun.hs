--- ./src/FRP/Reactive/Fun.hs.orig	2010-07-28 18:48:55.000000000 +0200
+++ ./src/FRP/Reactive/Fun.hs	2011-07-16 10:59:47.000000000 +0200
@@ -37,6 +37,9 @@
 import Control.Comonad
 
 import Data.Zip (Zip(..))
+import Data.Pointed
+import Data.Copointed
+import Data.Semigroup
 
 import Test.QuickCheck
 import Test.QuickCheck.Checkers
@@ -120,14 +123,8 @@
 instance Pointed (Fun t) where
   point = K
 
-instance Monoid t => Copointed (Fun t) where
-  extract = extract . apply
-
-instance Monoid t => Comonad (Fun t) where
-  duplicate (K   a) = K   (K a)
-  duplicate (Fun f) = Fun (Fun . duplicate f)
-
-
+instance (Semigroup t, Monoid t) => Copointed (Fun t) where
+  copoint = extract . apply
 
 ----------------------------------
 
