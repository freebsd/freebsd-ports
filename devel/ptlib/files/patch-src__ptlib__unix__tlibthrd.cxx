--- ./src/ptlib/unix/tlibthrd.cxx.orig	2009-02-14 22:04:11.000000000 +0100
+++ ./src/ptlib/unix/tlibthrd.cxx	2009-02-14 22:04:18.000000000 +0100
@@ -216,7 +216,7 @@
 {
   PWaitAndSignal m(threadMutex);
 
-  if (!activeThreads.Contains((unsigned)id)) 
+  if (!activeThreads.Contains((unsigned long)id)) 
     return PFalse;
 
   return pthread_kill(id, sig) == 0;
@@ -254,7 +254,7 @@
 #endif
 
   ((PProcess *)this)->activeThreads.DisallowDeleteObjects();
-  ((PProcess *)this)->activeThreads.SetAt((unsigned)PX_threadId, this);
+  ((PProcess *)this)->activeThreads.SetAt((unsigned long)PX_threadId, this);
 
   PX_firstTimeStart = PFalse;
 }
@@ -370,7 +370,7 @@
   PAssertPTHREAD(pthread_create, (&PX_threadId, &threadAttr, PX_ThreadStart, this));
 
   // put the thread into the thread list
-  process.activeThreads.SetAt((unsigned)PX_threadId, this);
+  process.activeThreads.SetAt((unsigned long)PX_threadId, this);
   if (process.activeThreads.GetSize() > highWaterMark)
     newHighWaterMark = highWaterMark = process.activeThreads.GetSize();
 
@@ -693,7 +693,7 @@
 {
   PProcess & process = PProcess::Current();
   process.threadMutex.Wait();
-  PThread * thread = process.activeThreads.GetAt((unsigned)pthread_self());
+  PThread * thread = process.activeThreads.GetAt((unsigned long)pthread_self());
   process.threadMutex.Signal();
   return thread;
 }
@@ -834,7 +834,7 @@
   }  
 
  // remove this thread from the active thread list
-  process.activeThreads.SetAt((unsigned)id, NULL);
+  process.activeThreads.SetAt((unsigned long)id, NULL);
 
   // delete the thread if required, note this is done this way to avoid
   // a race condition, the thread ID cannot be zeroed before the if!
