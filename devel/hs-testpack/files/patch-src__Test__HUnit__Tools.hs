--- ./src/Test/HUnit/Tools.hs.orig	2010-08-11 21:28:05.000000000 +0200
+++ ./src/Test/HUnit/Tools.hs	2011-03-13 15:12:06.976261554 +0100
@@ -61,7 +61,7 @@
     HU.TestLabel lbl $ HU.TestCase $
       do result <- localquickCheckWithResult config property
          case result of
-           Success _ -> return ()
+           Success _ _ _ -> return ()
            _ -> HU.assertFailure (show result)
 
 -- Modified from HUnit
@@ -159,7 +159,7 @@
 -- | Tests a property, using test arguments, produces a test result, and prints the results to 'stdout'.
 localquickCheckWithResult :: Testable prop => Args -> prop -> IO Result
 localquickCheckWithResult args p =
-  do tm  <- newTerminal
+  do tm  <- newStdioTerminal
      rnd <- case replay args of
               Nothing      -> newStdGen
               Just (rnd,_) -> return rnd
@@ -176,7 +176,6 @@
                  , collected         = []
                  , expectedFailure   = False
                  , randomSeed        = rnd
-                 , isShrinking       = False
                  , numSuccessShrinks = 0
                  , numTryShrinks     = 0
                  } (unGen (property p))
@@ -207,8 +206,7 @@
     runATest st f =
       do
         let size = computeSize st (numSuccessTests st) (numDiscardedTests st)
-        MkRose mres ts <- protectRose (unProp (f rnd1 size))
-        res <- mres
+        MkRose res ts <- protectRose (return $ unProp (f rnd1 size))
         callbackPostTest st res
      
         case ok res of
