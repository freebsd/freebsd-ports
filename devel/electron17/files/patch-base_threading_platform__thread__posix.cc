--- base/threading/platform_thread_posix.cc.orig	2022-05-13 07:19:54 UTC
+++ base/threading/platform_thread_posix.cc
@@ -75,7 +75,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::DisallowSingleton();
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && defined(PA_ALLOW_PCSCAN)
     internal::PCScan::NotifyThreadCreated(internal::GetStackPointer());
 #endif
@@ -334,6 +334,9 @@ bool PlatformThread::CanChangeThreadPriority(ThreadPri
 // static
 void PlatformThread::SetCurrentThreadPriorityImpl(ThreadPriority priority) {
 #if defined(OS_NACL)
+  NOTIMPLEMENTED();
+// avoid pledge(2) violation
+#elif defined(OS_BSD)
   NOTIMPLEMENTED();
 #else
   if (internal::SetCurrentThreadPriorityForPlatform(priority))
