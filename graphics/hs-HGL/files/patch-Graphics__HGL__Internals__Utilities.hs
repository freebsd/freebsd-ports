--- ./Graphics/HGL/Internals/Utilities.hs.orig	2009-11-03 15:50:11.000000000 +0100
+++ ./Graphics/HGL/Internals/Utilities.hs	2011-03-13 18:31:25.754332789 +0100
@@ -20,7 +20,7 @@
         modMVar, modMVar_
 	) where
 
-import qualified Control.Exception as E (bracket, try, IOException, tryJust, ioErrors)
+import qualified Control.OldException as E (bracket, try, IOException, tryJust, ioErrors)
 import Control.Concurrent( MVar, takeMVar, putMVar )
 
 bracket :: IO a -> (a -> IO b) -> (a -> IO c) -> IO c
