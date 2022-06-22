--- base/threading/platform_thread_posix.cc.orig	2022-05-20 04:30:53 UTC
+++ base/threading/platform_thread_posix.cc
@@ -76,7 +76,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::DisallowSingleton();
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && defined(PA_ALLOW_PCSCAN)
     internal::PCScan::NotifyThreadCreated(internal::GetStackPointer());
 #endif
@@ -363,6 +363,9 @@ bool PlatformThread::CanChangeThreadPriority(ThreadPri
 // static
 void PlatformThread::SetCurrentThreadPriorityImpl(ThreadPriority priority) {
 #if BUILDFLAG(IS_NACL)
+  NOTIMPLEMENTED();
+// avoid pledge(2) violation
+#elif BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
 #else
   if (internal::SetCurrentThreadPriorityForPlatform(priority))
