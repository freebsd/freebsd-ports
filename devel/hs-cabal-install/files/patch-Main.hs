--- ./Main.hs.orig	2012-04-17 17:17:31.000000000 +0200
+++ ./Main.hs	2012-11-23 20:47:29.000000000 +0100
@@ -75,7 +75,7 @@
        ( Verbosity, normal, intToVerbosity, lessVerbose )
 import qualified Paths_cabal_install (version)
 
-import System.Environment       (getArgs, getProgName)
+import System.Environment       (getArgs)
 import System.Exit              (exitFailure)
 import System.FilePath          (splitExtension, takeExtension)
 import System.Directory         (doesFileExist)
@@ -107,10 +107,10 @@
 
   where
     printCommandHelp help = do
-      pname <- getProgName
+      let pname = "cabal"
       putStr (help pname)
     printGlobalHelp help = do
-      pname <- getProgName
+      let pname = "cabal"
       configFile <- defaultConfigFile
       putStr (help pname)
       putStr $ "\nYou can edit the cabal configuration file to set defaults:\n"
