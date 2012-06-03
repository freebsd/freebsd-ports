--- ./IDoc.hs.orig	2004-05-14 08:54:08.000000000 +0200
+++ ./IDoc.hs	2012-05-13 00:56:43.000000000 +0200
@@ -181,10 +181,11 @@
 where
 
 -- standard libraries
-import Char   (isAlpha, isDigit, toUpper, isSpace, isDigit)
-import List   (isPrefixOf, intersperse)
-import IO     (stderr, hPutStr)
-import System (ExitCode(..), getArgs, exitWith)
+import Data.Char   (isAlpha, isDigit, toUpper, isSpace, isDigit)
+import Data.List   (isPrefixOf, intersperse)
+import System.IO     (stderr, hPutStr)
+import System.Environment (getArgs)
+import System.Exit (ExitCode(..), exitWith)
 
 -- extra library
 import GetOpt (ArgOrder(..), OptDescr(..), ArgDescr(..), usageInfo,
