--- ./Main.hs.orig	2005-05-29 21:27:39.000000000 +0200
+++ ./Main.hs	2012-05-12 19:33:06.000000000 +0200
@@ -19,7 +19,8 @@
 
 import CheckRDF
 import RDFConfig
-import System (getArgs, exitWith, ExitCode(..),getEnv)
+import System.Environment (getArgs, getEnv)
+import System.Exit (exitWith, ExitCode(..))
 
 main :: IO ()
 main = do files <- getArgs
