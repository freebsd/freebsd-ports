--- src/ptlib/common/osutils.cxx.orig	Wed May 23 20:36:01 2007
+++ src/ptlib/common/osutils.cxx	Wed May 23 20:36:32 2007
@@ -2356,21 +2356,21 @@ PReadWriteMutex::PReadWriteMutex()
 PReadWriteMutex::Nest * PReadWriteMutex::GetNest() const
 {
   PWaitAndSignal mutex(nestingMutex);
-  return nestedThreads.GetAt(POrdinalKey((PINDEX)PThread::GetCurrentThreadId()));
+  return nestedThreads.GetAt(POrdinalKey((INT)PThread::GetCurrentThreadId()));
 }
 
 
 void PReadWriteMutex::EndNest()
 {
   nestingMutex.Wait();
-  nestedThreads.RemoveAt(POrdinalKey((PINDEX)PThread::GetCurrentThreadId()));
+  nestedThreads.RemoveAt(POrdinalKey((INT)PThread::GetCurrentThreadId()));
   nestingMutex.Signal();
 }
 
 
 PReadWriteMutex::Nest & PReadWriteMutex::StartNest()
 {
-  POrdinalKey threadId = (PINDEX)PThread::GetCurrentThreadId();
+  POrdinalKey threadId = (INT)PThread::GetCurrentThreadId();
 
   nestingMutex.Wait();
 
