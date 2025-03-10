https://gitlab.haskell.org/ghc/ghc/-/merge_requests/13276

--- libraries/base/GHC/Event/KQueue.hsc.orig	2024-06-30 22:49:26 UTC
+++ libraries/base/GHC/Event/KQueue.hsc
@@ -44,8 +44,8 @@ import GHC.Event.Internal (Timeout(..))
 import GHC.Real (quotRem, fromIntegral)
 import GHC.Show (Show(show))
 import GHC.Event.Internal (Timeout(..))
-import System.Posix.Internals (c_close)
-import System.Posix.Types (Fd(..))
+import System.Posix.Internals (c_close, c_getpid)
+import System.Posix.Types (Fd(..), CPid)
 import qualified GHC.Event.Array as A
 
 #if defined(netbsd_HOST_OS)
@@ -73,19 +73,26 @@ data KQueue = KQueue {
 data KQueue = KQueue {
       kqueueFd     :: {-# UNPACK #-} !KQueueFd
     , kqueueEvents :: {-# UNPACK #-} !(A.Array Event)
+    , kqueuePid    :: {-# UNPACK #-} !CPid -- ^ pid, used to detect forks
     }
 
 new :: IO E.Backend
 new = do
   kqfd <- kqueue
   events <- A.new 64
-  let !be = E.backend poll modifyFd modifyFdOnce delete (KQueue kqfd events)
+  pid <- c_getpid
+  let !be = E.backend poll modifyFd modifyFdOnce delete (KQueue kqfd events pid)
   return be
 
 delete :: KQueue -> IO ()
 delete kq = do
-  _ <- c_close . fromKQueueFd . kqueueFd $ kq
-  return ()
+  -- detect forks: the queue isn't inherited by a child process created with
+  -- fork. Hence we mustn't try to close the old fd or we might close a random
+  -- one (e.g. the one used by timerfd, cf #24672).
+  pid <- c_getpid
+  when (pid == kqueuePid kq) $ do
+    _ <- c_close . fromKQueueFd . kqueueFd $ kq
+    return ()
 
 modifyFd :: KQueue -> Fd -> E.Event -> E.Event -> IO Bool
 modifyFd kq fd oevt nevt = do
