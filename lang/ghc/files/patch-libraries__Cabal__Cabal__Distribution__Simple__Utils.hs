--- ./libraries/Cabal/Cabal/Distribution/Simple/Utils.hs.orig	2012-11-23 17:07:58.000000000 +0100
+++ ./libraries/Cabal/Cabal/Distribution/Simple/Utils.hs	2012-11-23 19:38:03.000000000 +0100
@@ -95,6 +95,7 @@
         findModuleFile,
         findModuleFiles,
         getDirectoryContentsRecursive,
+        getProgramFromEnvironment,
 
         -- * simple file globbing
         matchFileGlob,
@@ -152,7 +153,7 @@
     ( getDirectoryContents, doesDirectoryExist, doesFileExist, removeFile
     , findExecutable )
 import System.Environment
-    ( getProgName )
+    ( getProgName, getEnvironment )
 import System.Cmd
     ( rawSystem )
 import System.Exit
@@ -670,6 +671,19 @@
         ignore ['.', '.'] = True
         ignore _          = False
 
+getProgramFromEnvironment :: Verbosity -> String -> String -> IO (Maybe FilePath)
+getProgramFromEnvironment verbosity prog name = do
+  debug verbosity $
+    "searching for " ++ prog ++ " in the environment (as " ++ name ++ ")."
+  res <- lookup name `fmap` getEnvironment
+  case res of
+    Nothing -> do
+      debug verbosity $ "falling back to searching in the path."
+      findExecutable prog
+    v@(Just val) -> do
+      debug verbosity $ "found as " ++ val ++ "."
+      return v
+
 ----------------
 -- File globbing
 
