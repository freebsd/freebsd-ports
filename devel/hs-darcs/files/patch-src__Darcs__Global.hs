--- ./src/Darcs/Global.hs.orig	2013-02-06 07:07:21.000000000 +0100
+++ ./src/Darcs/Global.hs	2014-07-13 18:40:00.000000000 +0200
@@ -61,7 +61,7 @@
 import Control.Monad ( when )
 import Control.Concurrent.MVar
 import Control.Exception.Extensible ( bracket_, catch, catchJust, SomeException
-                                    , block, unblock
+                                    , mask_
                                     )
 import Data.IORef ( IORef, newIORef, readIORef, writeIORef )
 import Data.IORef ( modifyIORef )
@@ -106,12 +106,12 @@
         exit
         prog
   where
-    exit = block $ do
+    exit = mask_ $ do
         Just actions <- swapMVar atexitActions Nothing
         -- from now on atexit will not register new actions
         mapM_ runAction actions
     runAction action =
-        catch (unblock action) $ \(exn :: SomeException) -> do
+        catch action $ \(exn :: SomeException) -> do
             hPutStrLn stderr $ "Exception thrown by an atexit registered action:"
             hPutStrLn stderr $ show exn
 
