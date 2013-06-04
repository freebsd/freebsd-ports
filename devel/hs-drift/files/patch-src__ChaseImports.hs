--- ./src/ChaseImports.hs.orig	2008-02-10 15:38:31.000000000 +0100
+++ ./src/ChaseImports.hs	2013-05-01 01:35:21.000000000 +0200
@@ -24,13 +24,14 @@
 import DataP
 import CommandP
 import ParseLib2
-import System
+import System.Environment
+import System.IO.Error
 import List
 import qualified Unlit
 import Monad
 import GenUtil
 
-try x = catch (x >>= return . Right) (return . Left)
+try x = catchIOError (x >>= return . Right) (return . Left)
 
 --- Split up input ---------------------------------------------------------
 splitString :: String -> String -> (String,String)
