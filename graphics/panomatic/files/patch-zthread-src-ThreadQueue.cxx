--- zthread/src/ThreadQueue.cxx.orig	2008-02-28 22:51:46.000000000 +0000
+++ zthread/src/ThreadQueue.cxx	2012-09-24 12:02:46.539117586 +0000
@@ -139,11 +139,13 @@
     
     // Wake the main thread,if its waiting, when the last pending-thread becomes available;
     // Otherwise, take note that no wait for pending threads to finish is needed
-    if(_userThreads.empty())
-      if(_waiter && _waiter != (ThreadImpl*)1)
+    if(_userThreads.empty()) {
+      if(_waiter && _waiter != (ThreadImpl*)1) {
         _waiter->getMonitor().notify();
-      else
+      } else {
         _waiter = (ThreadImpl*)!_waiter;
+      }
+    }
 
     ZTDEBUG("1 pending-thread added.\n");
 
