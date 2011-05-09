--- ./src/Test/QuickCheck/Instances.hs.orig	2010-08-11 21:28:05.000000000 +0200
+++ ./src/Test/QuickCheck/Instances.hs	2011-03-13 14:56:30.837261486 +0100
@@ -36,12 +36,14 @@
 instance (CoArbitrary k, CoArbitrary v, Eq k, Ord k) => CoArbitrary (Map.Map k v) where
     coarbitrary = coarbitrary . Map.keys
 
+{-
 instance Arbitrary Word8 where
     arbitrary = sized $ \n -> choose (0, min (fromIntegral n) maxBound)
 
 instance CoArbitrary Word8 where
     coarbitrary n = variant (if n >= 0 then 2 * x else 2 * x + 1)
                 where x = abs . fromIntegral $ n
+-}
 
 instance Random Word8 where
     randomR (a, b) g = (\(x, y) -> (fromInteger x, y)) $
