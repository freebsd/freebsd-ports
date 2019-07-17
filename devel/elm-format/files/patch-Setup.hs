--- Setup.hs.orig	2018-10-02 05:59:03 UTC
+++ Setup.hs
@@ -23,7 +23,7 @@ writeCustomFile :: FilePath -> IO ()
 writeCustomFile filepath = do
   putStrLn $ "Generating " ++ filepath ++ "..."
 
-  desc <- readProcess "git" ["describe", "--abbrev=8", "--always"] ""
+  desc <- readProcess "echo" ["%%PORTVERSION%%"] ""
   now <- readProcess "date" ["+%s"] ""
 
   writeFile filepath $ unlines
