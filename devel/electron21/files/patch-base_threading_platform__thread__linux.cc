--- base/threading/platform_thread_linux.cc.orig	2022-09-24 10:57:32 UTC
+++ base/threading/platform_thread_linux.cc
@@ -29,7 +29,9 @@
 
 #if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
 #include <pthread.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/resource.h>
 #include <sys/time.h>
 #include <sys/types.h>
@@ -132,7 +134,7 @@ long sched_setattr(pid_t pid,
 #endif  // !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 const FilePath::CharType kCgroupDirectory[] =
     FILE_PATH_LITERAL("/sys/fs/cgroup");
 
@@ -304,7 +306,7 @@ void SetThreadCgroupsForThreadType(PlatformThreadId th
 namespace internal {
 
 namespace {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 const struct sched_param kRealTimePrio = {8};
 #endif
 }  // namespace
@@ -330,7 +332,7 @@ const ThreadTypeToNiceValuePair kThreadTypeToNiceValue
 };
 
 bool CanSetThreadTypeToRealtimeAudio() {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
   // A non-zero soft-limit on RLIMIT_RTPRIO is required to be allowed to invoke
   // pthread_setschedparam in SetCurrentThreadTypeForPlatform().
   struct rlimit rlim;
@@ -342,7 +344,7 @@ bool CanSetThreadTypeToRealtimeAudio() {
 
 bool SetCurrentThreadTypeForPlatform(ThreadType thread_type,
                                      MessagePumpType pump_type_hint) {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
   // For legacy schedtune interface
   SetThreadCgroupsForThreadType(PlatformThread::CurrentId(), thread_type);
 
@@ -361,7 +363,7 @@ bool SetCurrentThreadTypeForPlatform(ThreadType thread
 
 absl::optional<ThreadPriorityForTest>
 GetCurrentThreadPriorityForPlatformForTest() {
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
   int maybe_sched_rr = 0;
   struct sched_param maybe_realtime_prio = {0};
   if (pthread_getschedparam(pthread_self(), &maybe_sched_rr,
@@ -380,7 +382,7 @@ GetCurrentThreadPriorityForPlatformForTest() {
 void PlatformThread::SetName(const std::string& name) {
   ThreadIdNameManager::GetInstance()->SetName(name);
 
-#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_AIX) && !BUILDFLAG(IS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
@@ -410,8 +412,10 @@ void PlatformThread::SetThreadType(ProcessId process_i
   // priority.
   CHECK_NE(thread_id, process_id);
 
+#if !BUILDFLAG(IS_BSD)
   // For legacy schedtune interface
   SetThreadCgroupsForThreadType(thread_id, thread_type);
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS)
   // For upstream uclamp interface. We try both legacy (schedtune, as done
