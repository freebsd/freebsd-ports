--- ghc/utils/ghc-pkg/Main.hs.orig	Tue May 24 21:09:06 2005
+++ ghc/utils/ghc-pkg/Main.hs	Tue May 24 21:32:53 2005
@@ -190,9 +190,9 @@ checkConfigAccess pkgconf = do
 maybeRestoreOldConfig :: String -> IO () -> IO ()
 maybeRestoreOldConfig conf_file io
   = my_catch io (\e -> do
-        hPutStr stdout "\nWARNING: an error was encountered while the new \n\ 
-        	       \configuration was being written.  Attempting to \n\ 
-        	       \restore the old configuration... "
+        hPutStr stdout ("\nWARNING: an error was encountered while the new \n"++
+        	       "configuration was being written.  Attempting to \n"++
+        	       "restore the old configuration... ")
 	renameFile (conf_file ++ ".old")  conf_file
         hPutStrLn stdout "done."
 	my_throw e
