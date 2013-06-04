--- ./src/Test/QuickCheck/Tools.hs.orig	2013-02-25 16:03:46.000000000 +0100
+++ ./src/Test/QuickCheck/Tools.hs	2013-05-04 00:42:02.274698941 +0200
@@ -23,14 +23,18 @@
                               
                              )
 where
+#if MIN_VERSION_QuickCheck(2,6,0)
+import Test.QuickCheck hiding (Result, reason, interrupted)
+#else
 import Test.QuickCheck hiding (Result, reason)
+#endif
 import Test.QuickCheck.Property
 
 {- | Compare two values.  If same, the test passes.  If different, the result indicates
 what was expected and what was received as part of the error. -}
 (@=?) :: (Eq a, Show a) => a -> a -> Result
 expected @=? actual = 
-        MkResult {ok = Just (expected == actual), 
+        result {  ok = Just (expected == actual), 
                   expect = True, interrupted = False,
                   reason = "Result: expected " ++ show expected ++ ", got " ++ show actual,
                   stamp = [], callbacks = []}
