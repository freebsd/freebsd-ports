--- src/ThreadQueue.cxx.orig	2005-03-13 03:55:23 UTC
+++ src/ThreadQueue.cxx
@@ -139,11 +139,12 @@ namespace ZThread {
     
     // Wake the main thread,if its waiting, when the last pending-thread becomes available;
     // Otherwise, take note that no wait for pending threads to finish is needed
-    if(_userThreads.empty())
+    if(_userThreads.empty()) {
       if(_waiter && _waiter != (ThreadImpl*)1)
         _waiter->getMonitor().notify();
       else
         _waiter = (ThreadImpl*)!_waiter;
+    }
 
     ZTDEBUG("1 pending-thread added.\n");
 
