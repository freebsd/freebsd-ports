--- chrome/browser/task_manager/sampling/task_group.h.orig	2025-10-21 20:19:54 UTC
+++ chrome/browser/task_manager/sampling/task_group.h
@@ -41,7 +41,7 @@ inline constexpr int kUnsupportedVMRefreshFlags =
     REFRESH_TYPE_WEBCACHE_STATS | REFRESH_TYPE_NETWORK_USAGE |
     REFRESH_TYPE_IDLE_WAKEUPS | REFRESH_TYPE_HANDLES | REFRESH_TYPE_START_TIME |
     REFRESH_TYPE_CPU_TIME | REFRESH_TYPE_PRIORITY |
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     REFRESH_TYPE_FD_COUNT |
 #endif
     REFRESH_TYPE_HARD_FAULTS;
@@ -141,7 +141,7 @@ class TaskGroup {
   int64_t hard_faults_per_second() const { return hard_faults_per_second_; }
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   int open_fd_count() const { return open_fd_count_; }
   void set_open_fd_count(int open_fd_count) { open_fd_count_ = open_fd_count; }
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
@@ -156,7 +156,7 @@ class TaskGroup {
 
   void RefreshWindowsHandles();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   void OnOpenFdCountRefreshDone(int open_fd_count);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
 
@@ -226,7 +226,7 @@ class TaskGroup {
   int64_t user_peak_handles_ = -1;
   int64_t hard_faults_per_second_ = -1;
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // The number of file descriptors currently open by the process.
   int open_fd_count_ = -1;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
