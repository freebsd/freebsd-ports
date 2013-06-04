--- ./Setup.hs.orig	2012-02-28 22:01:23.000000000 +0100
+++ ./Setup.hs	2013-05-01 00:55:07.000000000 +0200
@@ -4,6 +4,7 @@
 
 import System.Directory
 import System.FilePath
+import System.IO.Error
 
 -- Define __HADDOCK__ when building documentation.
 main = defaultMainWithHooks simpleUserHooks {
@@ -19,4 +20,4 @@
 removePreProcessedFiles dir = do
   putStrLn $ "Trying to remove source in: " ++ dir
   removeFile (dir </> "System/BSD/Sysctl.hs")
-    `catch` \_ -> putStrLn "Could not find source file!" >> return ()
+    `catchIOError` \_ -> putStrLn "Could not find source file!" >> return ()
