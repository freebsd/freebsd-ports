--- src/Cabal.hs.orig	2021-02-24 05:03:56 UTC
+++ src/Cabal.hs
@@ -68,6 +68,7 @@ cabalInstallHls versionNumber args = do
     , "--max-backjumps=5000"
     , "--overwrite-policy=always"
     , "--project-file=" ++ projectFile
+    , "--disable-tests", "--disable-benchmarks"
     ]
     ++ installMethod
     ++ args
