This test seems to be missing input files

--- cabal-install/tests/IntegrationTests2.hs.orig	2026-09-30 10:37:26 UTC
+++ cabal-install/tests/IntegrationTests2.hs
@@ -203,11 +203,11 @@ tests config =
       [ testCase "Test Config options for commented options" testConfigOptionComments
       , testCase "Test Ignore Project Flag" testIgnoreProjectFlag
       ]
-  , dependentTestGroup
-      "haddock-project"
-      AllFinish
-      [ testCase "dependencies" (testHaddockProjectDependencies config)
-      ]
+--   , dependentTestGroup
+--       "haddock-project"
+--       AllFinish
+--       [ testCase "dependencies" (testHaddockProjectDependencies config)
+--       ]
   ]
 
 testTargetSelectors :: (String -> IO ()) -> Assertion
