--- ./src/ptlib/common/osutils.cxx.orig	2009-02-14 22:04:50.000000000 +0100
+++ ./src/ptlib/common/osutils.cxx	2009-02-14 22:04:55.000000000 +0100
@@ -2152,21 +2152,21 @@
 PReadWriteMutex::Nest * PReadWriteMutex::GetNest() const
 {
   PWaitAndSignal mutex(nestingMutex);
-  return nestedThreads.GetAt(POrdinalKey((PINDEX)PThread::GetCurrentThreadId()));
+  return nestedThreads.GetAt(POrdinalKey((unsigned long)PThread::GetCurrentThreadId()));
 }
 
 
 void PReadWriteMutex::EndNest()
 {
   nestingMutex.Wait();
-  nestedThreads.RemoveAt(POrdinalKey((PINDEX)PThread::GetCurrentThreadId()));
+  nestedThreads.RemoveAt(POrdinalKey((unsigned long)PThread::GetCurrentThreadId()));
   nestingMutex.Signal();
 }
 
 
 PReadWriteMutex::Nest & PReadWriteMutex::StartNest()
 {
-  POrdinalKey threadId = (PINDEX)PThread::GetCurrentThreadId();
+  POrdinalKey threadId = (unsigned long)PThread::GetCurrentThreadId();
 
   nestingMutex.Wait();
 
