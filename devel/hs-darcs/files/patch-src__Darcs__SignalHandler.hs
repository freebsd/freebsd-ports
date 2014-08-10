--- ./src/Darcs/SignalHandler.hs.orig	2013-02-06 07:07:21.000000000 +0100
+++ ./src/Darcs/SignalHandler.hs	2014-07-13 18:39:00.000000000 +0200
@@ -27,7 +27,7 @@
 import System.Exit ( exitWith, ExitCode ( ExitFailure ) )
 import Control.Concurrent ( ThreadId, myThreadId )
 import Control.Exception.Extensible
-            ( catch, throw, throwTo, block, unblock,
+            ( catch, throw, throwTo, mask_,
               Exception(..), SomeException(..), IOException )
 import System.Posix.Files ( getFdStatus, isNamedPipe )
 import System.Posix.IO ( stdOutput )
@@ -128,8 +128,9 @@
          | otherwise                             = throw ioe
 
 withSignalsBlocked :: IO a -> IO a
-withSignalsBlocked job = block (job >>= \r ->
-                           unblock(return r) `catchSignal` couldnt_do r)
+withSignalsBlocked job = do
+    r <- mask_ job
+    (return r) `catchSignal` couldnt_do r
     where couldnt_do r s | s == sigINT = oops "interrupt" r
                          | s ==  sigHUP = oops "HUP" r
                          | s ==  sigABRT = oops "ABRT" r
