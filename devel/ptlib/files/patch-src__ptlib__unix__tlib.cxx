--- ./src/ptlib/unix/tlib.cxx.orig	2009-02-14 22:02:51.000000000 +0100
+++ ./src/ptlib/unix/tlib.cxx	2009-02-14 22:03:09.000000000 +0100
@@ -400,7 +400,7 @@
 {
   if (PProcessInstance != NULL) {
     PWaitAndSignal m(PProcessInstance->threadMutex);
-    PThread & thread = PProcessInstance->activeThreads[(unsigned)id];
+    PThread & thread = PProcessInstance->activeThreads[(unsigned long)id];
     return thread.GetThreadName();
   }
   return psprintf("%08x", id);
