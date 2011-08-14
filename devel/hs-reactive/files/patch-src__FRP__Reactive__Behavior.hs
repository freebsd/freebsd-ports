--- ./src/FRP/Reactive/Behavior.hs.orig	2010-07-28 18:48:55.000000000 +0200
+++ ./src/FRP/Reactive/Behavior.hs	2011-07-16 11:20:55.000000000 +0200
@@ -33,6 +33,8 @@
 
 import Control.Compose ((:.)(..),unO)
 
+import Data.Copointed
+import Data.Semigroup
 import Data.VectorSpace
 import Data.AffineSpace
 
@@ -276,7 +278,7 @@
 
 instance (Functor g, Functor f, Copointed g, Copointed f)
       => Copointed (g :. f) where
-  extract = extract . extract . unO
+  copoint = copoint . copoint . unO
 
 -- instance (Comonad g, Comonad f) => Comonad (g :. f) where
 --   duplicate = inO (fmap duplicate . duplicate)
@@ -297,7 +299,7 @@
 -- instance Comonad (g :. f) where
 --   duplicate 
 
-deriving instance (Monoid tr, Monoid tf) => Copointed (BehaviorG tr tf) 
+deriving instance (Monoid tr, Monoid tf, Semigroup tf) => Copointed (BehaviorG tr tf) 
 
 -- ITime and TimeT are not currently monoids.  They can be when I wrap
 -- them in the Sum monoid constructor, in which mempty = 0 and mappend =
