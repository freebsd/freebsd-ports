--- ./Epic/Language.lhs.orig	2012-02-28 00:44:29.000000000 +0100
+++ ./Epic/Language.lhs	2013-05-01 00:03:23.000000000 +0200
@@ -5,6 +5,7 @@
 
 > import Control.Monad
 > import System.IO
+> import System.IO.Error
 > import System.Directory
 > import System.Environment
 
@@ -377,9 +378,9 @@
 >               openTempFile dir "esc"
 
 > environment :: String -> IO (Maybe String)
-> environment x = catch (do e <- getEnv x
->                           return (Just e))
->                       (\_ -> return Nothing)
+> environment x = catchIOError (do e <- getEnv x
+>                                  return (Just e))
+>                              (\_ -> return Nothing)
 
 Some tests
 
