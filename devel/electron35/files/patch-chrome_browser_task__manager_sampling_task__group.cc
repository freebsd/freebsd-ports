--- chrome/browser/task_manager/sampling/task_group.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/task_manager/sampling/task_group.cc
@@ -36,7 +36,7 @@ const int kBackgroundRefreshTypesMask =
 #if BUILDFLAG(IS_WIN)
     REFRESH_TYPE_START_TIME | REFRESH_TYPE_CPU_TIME |
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     REFRESH_TYPE_FD_COUNT |
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
 #if BUILDFLAG(ENABLE_NACL)
@@ -117,7 +117,7 @@ TaskGroup::TaskGroup(
 #if BUILDFLAG(ENABLE_NACL)
       nacl_debug_stub_port_(nacl::kGdbDebugStubPortUnknown),
 #endif  // BUILDFLAG(ENABLE_NACL)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       open_fd_count_(-1),
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
       idle_wakeups_per_second_(-1),
@@ -132,7 +132,7 @@ TaskGroup::TaskGroup(
                             weak_ptr_factory_.GetWeakPtr()),
         base::BindRepeating(&TaskGroup::OnIdleWakeupsRefreshDone,
                             weak_ptr_factory_.GetWeakPtr()),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
         base::BindRepeating(&TaskGroup::OnOpenFdCountRefreshDone,
                             weak_ptr_factory_.GetWeakPtr()),
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
@@ -302,7 +302,7 @@ void TaskGroup::OnRefreshNaClDebugStubPortDone(int nac
 }
 #endif  // BUILDFLAG(ENABLE_NACL)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 void TaskGroup::OnOpenFdCountRefreshDone(int open_fd_count) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
 
