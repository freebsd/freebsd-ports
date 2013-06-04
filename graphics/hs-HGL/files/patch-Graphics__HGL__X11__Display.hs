--- ./Graphics/HGL/X11/Display.hs.orig	2009-11-03 15:50:11.000000000 +0100
+++ ./Graphics/HGL/X11/Display.hs	2013-05-01 02:01:44.000000000 +0200
@@ -14,12 +14,12 @@
 import Control.Monad (when)
 import Data.Maybe (isJust)
 import System.Environment (getEnv)
-import System.IO.Error (try)
+import System.IO.Error (tryIOError, catchIOError)
 import System.IO.Unsafe (unsafePerformIO)
 
 getDisplayName :: IO String
 getDisplayName = do
-  disp <- try (getEnv "DISPLAY")
+  disp <- tryIOError (getEnv "DISPLAY")
   return (either (const ":0.0") id disp)
 
 displayRef :: MVar (Maybe X.Display)
@@ -32,7 +32,7 @@
   openDisplay'
  where
   openDisplay' = do      
-    display <- X.openDisplay host `catch` \ err -> 
+    display <- X.openDisplay host `catchIOError` \ err -> 
                  ioError (userError ("Unable to open X display " ++ host))
     modMVar displayRef (const $ Just display)
     return display
