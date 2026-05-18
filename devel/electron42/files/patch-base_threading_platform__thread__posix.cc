--- base/threading/platform_thread_posix.cc.orig	2026-04-28 21:06:17 UTC
+++ base/threading/platform_thread_posix.cc
@@ -6,6 +6,9 @@
 
 #include <errno.h>
 #include <pthread.h>
+#if BUILDFLAG(IS_BSD)
+#include <pthread_np.h>
+#endif
 #include <sched.h>
 #include <stddef.h>
 #include <stdint.h>
@@ -80,6 +83,7 @@ void* ThreadFunc(void* params) {
       base::DisallowSingleton();
     }
 
+#if !BUILDFLAG(IS_BSD)
 #if PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
     partition_alloc::internal::StackTopRegistry::Get().NotifyThreadCreated();
 #endif
@@ -93,6 +97,7 @@ void* ThreadFunc(void* params) {
     // where they were created. This explicitly sets the priority of all new
     // threads.
     PlatformThread::SetCurrentThreadType(thread_params->thread_type);
+#endif
   }
 
   ThreadIdNameManager::GetInstance()->RegisterThread(
@@ -270,6 +275,10 @@ PlatformThreadId PlatformThreadBase::CurrentId() {
 
 #elif BUILDFLAG(IS_POSIX) && BUILDFLAG(IS_AIX)
   return PlatformThreadId(pthread_self());
+#elif BUILDFLAG(IS_OPENBSD)
+  return PlatformThreadId(static_cast<uint64_t>(getthrid()));
+#elif BUILDFLAG(IS_FREEBSD)
+  return PlatformThreadId(static_cast<uint64_t>(pthread_getthreadid_np()));
 #elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_AIX)
   return PlatformThreadId(reinterpret_cast<int64_t>(pthread_self()));
 #endif
@@ -363,6 +372,9 @@ bool PlatformThreadBase::CanChangeThreadType(ThreadTyp
 
 // static
 bool PlatformThreadBase::CanChangeThreadType(ThreadType from, ThreadType to) {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   if (from >= to) {
     // Decreasing thread priority on POSIX is always allowed.
     return true;
@@ -372,10 +384,15 @@ bool PlatformThreadBase::CanChangeThreadType(ThreadTyp
   }
 
   return internal::CanLowerNiceTo(internal::ThreadTypeToNiceValue(to));
+#endif
 }
 
 // static
 ThreadType PlatformThreadBase::GetCurrentEffectiveThreadTypeForTest() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return ThreadType::kDefault;
+#else
   // Mirrors SetCurrentThreadPriority()'s implementation.
   auto platform_specific_priority =
       internal::GetCurrentEffectiveThreadTypeForPlatformForTest();  // IN-TEST
@@ -386,6 +403,7 @@ ThreadType PlatformThreadBase::GetCurrentEffectiveThre
   int nice_value = internal::GetCurrentThreadNiceValue();
 
   return internal::NiceValueToThreadTypeForTest(nice_value);  // IN-TEST
+#endif
 }
 
 #endif  // !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_FUCHSIA)
