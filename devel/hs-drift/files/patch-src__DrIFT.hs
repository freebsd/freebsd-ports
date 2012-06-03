--- ./src/DrIFT.hs.orig	2008-02-10 15:38:31.000000000 +0100
+++ ./src/DrIFT.hs	2012-05-13 11:52:13.000000000 +0200
@@ -17,7 +17,8 @@
 import RuleUtils(Rule,Tag)
 import Version
 import qualified Rules(rules)
-import qualified System
+import qualified System.Environment
+import System.IO
 
 data Op = OpList | OpDerive | OpVersion
 
@@ -78,7 +79,7 @@
 
 header = "Usage: DrIFT [OPTION...] file"
 main = do
-    argv <- System.getArgs
+    argv <- System.Environment.getArgs
     (env,n) <- case (getOpt Permute options argv) of
 	(as,n,[]) -> return (foldr ($) env as ,n)
 	(_,_,errs) -> putErrDie (concat errs ++ usageInfo header options)
