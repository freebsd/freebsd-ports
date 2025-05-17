--- content/browser/child_thread_type_switcher_linux.cc.orig	2025-04-22 20:15:27 UTC
+++ content/browser/child_thread_type_switcher_linux.cc
@@ -20,6 +20,9 @@ void SetThreadTypeOnLauncherThread(base::ProcessId pee
                                    base::ThreadType thread_type) {
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
 
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+#else
   bool ns_pid_supported = false;
   pid_t peer_tid =
       base::FindThreadID(peer_pid, ns_tid.raw(), &ns_pid_supported);
@@ -41,6 +44,7 @@ void SetThreadTypeOnLauncherThread(base::ProcessId pee
   base::PlatformThread::SetThreadType(peer_pid,
                                       base::PlatformThreadId(peer_tid),
                                       thread_type, base::IsViaIPC(true));
+#endif
 }
 
 }  // namespace
@@ -69,7 +73,7 @@ void ChildThreadTypeSwitcher::SetPid(base::ProcessId c
   }
 }
 
-void ChildThreadTypeSwitcher::SetThreadType(int32_t ns_tid,
+void ChildThreadTypeSwitcher::SetThreadType(uint64_t ns_tid,
                                             base::ThreadType thread_type) {
   // This function is only used on platforms with 32-bit thread ids.
   static_assert(sizeof(ns_tid) == sizeof(base::PlatformThreadId));
