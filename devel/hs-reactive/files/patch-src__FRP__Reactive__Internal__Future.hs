--- ./src/FRP/Reactive/Internal/Future.hs.orig	2010-07-28 18:48:55.000000000 +0200
+++ ./src/FRP/Reactive/Internal/Future.hs	2012-10-04 23:19:51.000000000 +0200
@@ -23,7 +23,8 @@
 
 import Control.Applicative (Applicative(..))
 
-import Control.Comonad (Copointed,Comonad)
+import Control.Comonad
+import Data.Copointed
 
 import Test.QuickCheck
 
