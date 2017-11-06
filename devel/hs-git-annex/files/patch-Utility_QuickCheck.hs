--- Utility/QuickCheck.hs.orig	2017-06-12 17:56:05 UTC
+++ Utility/QuickCheck.hs
@@ -35,9 +35,6 @@ instance (Arbitrary v, Ord v) => Arbitrary (S.Set v) w
 instance Arbitrary POSIXTime where
 	arbitrary = fromInteger <$> nonNegative arbitrarySizedIntegral
 
-instance Arbitrary EpochTime where
-	arbitrary = fromInteger <$> nonNegative arbitrarySizedIntegral
-
 {- Pids are never negative, or 0. -}
 instance Arbitrary ProcessID where
 	arbitrary = arbitrarySizedBoundedIntegral `suchThat` (> 0)
