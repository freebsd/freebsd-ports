--- ./MultiView.hs.orig	2010-09-15 16:26:38.000000000 +0200
+++ ./MultiView.hs	2012-05-12 22:16:41.000000000 +0200
@@ -109,7 +109,7 @@
   ["import qualified Print" ++ cnc | cnc <- cncs] ++
   ["import Abs" ++ abs,
    "import ErrM",
-   "import System (getArgs)",
+   "import System.Environment (getArgs)",
    "",
    "main :: IO ()",
    "main = do",
