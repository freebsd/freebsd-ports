--- ./formats/c/CTop.hs.orig	2010-09-15 16:26:38.000000000 +0200
+++ ./formats/c/CTop.hs	2012-05-13 12:06:24.160466196 +0200
@@ -26,10 +26,9 @@
 import CFtoCSkel
 import CFtoCPrinter
 import CFtoLatex
--- import System
 import GetCF
 import Char
-import System
+import System.Exit
 
 makeC :: Bool -> String -> FilePath -> IO ()
 makeC make name file = do
