--- ./src/Test/HUnit/Tools.hs.orig	2012-02-28 23:20:32.000000000 +0100
+++ ./src/Test/HUnit/Tools.hs	2012-10-04 00:04:08.000000000 +0200
@@ -128,7 +128,11 @@
 >        q "Integer -> Int (safe bounds)" prop_integer_to_int_pass]
 -}
 qc2hu :: QC.Testable a => Int -> String -> a -> HU.Test
+#if MIN_VERSION_QuickCheck(2,5,0)
+qc2hu maxTest = qccheck (stdArgs {maxSuccess = maxTest, maxDiscardRatio = 1000})
+#else
 qc2hu maxTest = qccheck (stdArgs {maxSuccess = maxTest, maxDiscard = 20000})
+#endif
 
 {- | Run verbose tests.  Example:
 
@@ -174,7 +178,11 @@
               Just (rnd,_) -> return rnd
      test MkState{ terminal          = tm
                  , maxSuccessTests   = maxSuccess args
+#if MIN_VERSION_QuickCheck(2,5,0)
+                 , maxDiscardedTests = maxDiscardRatio args
+#else
                  , maxDiscardedTests = maxDiscard args
+#endif
                  , computeSize       = case replay args of
                                          Nothing    -> \n d -> (n * maxSize args)
                                                          `div` maxSuccess args
