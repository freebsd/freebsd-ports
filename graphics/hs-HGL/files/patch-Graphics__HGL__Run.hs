--- ./Graphics/HGL/Run.hs.orig	2009-11-03 15:50:11.000000000 +0100
+++ ./Graphics/HGL/Run.hs	2013-05-01 01:51:50.000000000 +0200
@@ -24,7 +24,7 @@
 import Graphics.HGL.Internals.Utilities (safeTry)
 import Control.Concurrent (forkIO, yield)
 import Data.IORef( newIORef, readIORef, writeIORef )
-import System.IO.Error (try)
+import System.IO.Error (tryIOError)
 #endif
 
 ----------------------------------------------------------------
@@ -60,7 +60,7 @@
   beginGraphics
   quit <- newIORef False
   safeTry $ do
-    forkIO (try m >> writeIORef quit True)
+    forkIO (tryIOError m >> writeIORef quit True)
     yield
     handleEvents (readIORef quit)
   endGraphics
