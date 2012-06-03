--- ./formats/cpp/CPPTop.hs.orig	2010-09-15 16:26:38.000000000 +0200
+++ ./formats/cpp/CPPTop.hs	2012-05-13 12:14:55.788469382 +0200
@@ -27,10 +27,9 @@
 import CFtoCVisitSkel
 import CFtoCPPPrinter
 import CFtoLatex
-import System
 import GetCF
 import Char
-import System
+import System.Exit
 
 makeCPP :: Bool -> String -> FilePath -> IO ()
 makeCPP make name file = do
