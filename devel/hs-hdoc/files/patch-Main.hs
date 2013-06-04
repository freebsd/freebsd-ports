--- ./Main.hs.orig	2004-05-18 00:27:27.000000000 +0200
+++ ./Main.hs	2013-04-30 23:59:28.000000000 +0200
@@ -5,7 +5,8 @@
 import List
 import Maybe
 import Monad
-import System
+import System.Environment
+import System.IO.Error
 import GetOpt
 
 import Parser
@@ -338,7 +339,7 @@
     case preProc of
     Nothing -> return $ Left (NoPreprocessor file)
     Just (msg, action) ->
-	do res <- try (readFile file)
+	do res <- tryIOError (readFile file)
 	   case res of
 	     Left _     -> return $ Left NotFound
 	     Right cont -> return $ Right (action cont,msg)
