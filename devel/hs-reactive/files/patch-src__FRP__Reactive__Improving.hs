--- ./src/FRP/Reactive/Improving.hs.orig	2010-07-28 18:48:55.000000000 +0200
+++ ./src/FRP/Reactive/Improving.hs	2012-05-13 01:17:34.000000000 +0200
@@ -178,13 +178,13 @@
 
 -- TODO: revisit (=-=).  Maybe it doesn't have to test for full equality.
 
-genGE :: (Arbitrary a, Num a) => Improving a -> Gen (Improving a)
+genGE :: (Arbitrary a, Eq a, Num a) => Improving a -> Gen (Improving a)
 genGE i = add i <$> oneof [pure 0, positive]
 
 -- I didn't use nonNegative in genGE, because I want zero pretty often,
 -- especially for the antiSymmetric law.
 
-add :: Num a => Improving a -> a -> Improving a
+add :: (Eq a, Num a) => Improving a -> a -> Improving a
 add (Imp x comp) dx = Imp (x + dx) (comp . subtract dx)
 
 batch :: TestBatch
