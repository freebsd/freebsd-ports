--- ./src/ThreadQueue.cxx.orig	2005-03-12 22:55:23.000000000 -0500
+++ ./src/ThreadQueue.cxx	2013-01-17 13:48:32.000000000 -0500
@@ -139,11 +139,12 @@
     
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
 
