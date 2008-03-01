--- src/ptlib/unix/tlibthrd.cxx.orig	Wed May 23 20:31:51 2007
+++ src/ptlib/unix/tlibthrd.cxx	Wed May 23 20:35:26 2007
@@ -754,7 +754,7 @@ BOOL PProcess::PThreadKill(pthread_t id,
 {
   PWaitAndSignal m(threadMutex);
 
-  if (!activeThreads.Contains((unsigned)id)) 
+  if (!activeThreads.Contains((uintptr_t)id)) 
     return FALSE;
 
   return pthread_kill(id, sig) == 0;
@@ -792,7 +792,7 @@ void PThread::InitialiseProcessThread()
 #endif
 
   ((PProcess *)this)->activeThreads.DisallowDeleteObjects();
-  ((PProcess *)this)->activeThreads.SetAt((unsigned)PX_threadId, this);
+  ((PProcess *)this)->activeThreads.SetAt((uintptr_t)PX_threadId, this);
 
   PX_firstTimeStart = FALSE;
 
@@ -906,7 +906,7 @@ void PThread::Restart()
   PAssertPTHREAD(pthread_create, (&PX_threadId, &threadAttr, PX_ThreadStart, this));
 
   // put the thread into the thread list
-  process.activeThreads.SetAt((unsigned)PX_threadId, this);
+  process.activeThreads.SetAt((uintptr_t)PX_threadId, this);
   if (process.activeThreads.GetSize() > highWaterMark)
     newHighWaterMark = highWaterMark = process.activeThreads.GetSize();
 
@@ -1229,7 +1229,7 @@ PThread * PThread::Current()
 {
   PProcess & process = PProcess::Current();
   process.threadMutex.Wait();
-  PThread * thread = process.activeThreads.GetAt((unsigned)pthread_self());
+  PThread * thread = process.activeThreads.GetAt((uintptr_t)pthread_self());
   process.threadMutex.Signal();
   return thread;
 }
@@ -1362,7 +1362,7 @@ void PThread::PX_ThreadEnd(void * arg)
   }  
 
  // remove this thread from the active thread list
-  process.activeThreads.SetAt((unsigned)id, NULL);
+  process.activeThreads.SetAt((uintptr_t)id, NULL);
 
   // delete the thread if required, note this is done this way to avoid
   // a race condition, the thread ID cannot be zeroed before the if!
