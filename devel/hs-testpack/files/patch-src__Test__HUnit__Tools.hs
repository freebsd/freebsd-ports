--- ./src/Test/HUnit/Tools.hs.orig	2013-02-25 16:03:46.000000000 +0100
+++ ./src/Test/HUnit/Tools.hs	2013-05-04 00:47:19.298796917 +0200
@@ -22,7 +22,11 @@
 import Test.QuickCheck.Gen
 import Test.QuickCheck.State
 import qualified Test.QuickCheck.Property as P
+#if MIN_VERSION_QuickCheck(2,6,0)
+import Test.QuickCheck.Property hiding (Result(reason), interrupted)
+#else
 import Test.QuickCheck.Property hiding (Result(reason))
+#endif
 import qualified Control.Exception
 import qualified Test.HUnit as HU
 import System.Random
@@ -128,7 +132,11 @@
 >        q "Integer -> Int (safe bounds)" prop_integer_to_int_pass]
 -}
 qc2hu :: QC.Testable a => Int -> String -> a -> HU.Test
+#if MIN_VERSION_QuickCheck(2,5,0)
+qc2hu maxTest = qccheck (stdArgs {maxSuccess = maxTest, maxDiscardRatio = 1000})
+#else
 qc2hu maxTest = qccheck (stdArgs {maxSuccess = maxTest, maxDiscard = 20000})
+#endif
 
 {- | Run verbose tests.  Example:
 
@@ -163,18 +171,26 @@
 -- | Tests a property, using test arguments, produces a test result, and prints the results to 'stdout'.
 localquickCheckWithResult :: Testable prop => Args -> prop -> IO Result
 localquickCheckWithResult args p =
-  do 
+#if MIN_VERSION_QuickCheck(2,6,0)
+  (if chatty args then withStdioTerminal else withNullTerminal) $ \tm -> do
+#else
+  do
 #if MIN_VERSION_QuickCheck(2,3,0)
      tm  <- if chatty args then newStdioTerminal else newNullTerminal
 #else
      tm  <- newTerminal
 #endif
+#endif
      rnd <- case replay args of
               Nothing      -> newStdGen
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
@@ -190,6 +206,10 @@
 #endif
                  , numSuccessShrinks = 0
                  , numTryShrinks     = 0
+#if MIN_VERSION_QuickCheck(2,6,0)
+                 , numRecentlyDiscardedTests = 0
+                 , numTotTryShrinks          = 0
+#endif
                  } (unGen (property p))
   where 
 --------------------------------------------------------------------------
@@ -288,5 +308,8 @@
                                , numShrinks = numShrinks
                                , output     = theOutput
 #endif
+#if MIN_VERSION_QuickCheck(2,6,0)
+                               , interrupted = False
+#endif
                                }
       where (rnd1,rnd2) = split (randomSeed st)
