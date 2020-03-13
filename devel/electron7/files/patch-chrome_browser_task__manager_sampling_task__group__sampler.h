--- chrome/browser/task_manager/sampling/task_group_sampler.h.orig	2019-12-12 12:39:16 UTC
+++ chrome/browser/task_manager/sampling/task_group_sampler.h
@@ -32,9 +32,9 @@ class TaskGroupSampler : public base::RefCountedThread
   using OnCpuRefreshCallback = base::Callback<void(double)>;
   using OnSwappedMemRefreshCallback = base::Callback<void(int64_t)>;
   using OnIdleWakeupsCallback = base::Callback<void(int)>;
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   using OnOpenFdCountCallback = base::Callback<void(int)>;
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   using OnProcessPriorityCallback = base::Callback<void(bool)>;
 
   TaskGroupSampler(
@@ -43,9 +43,9 @@ class TaskGroupSampler : public base::RefCountedThread
       const OnCpuRefreshCallback& on_cpu_refresh,
       const OnSwappedMemRefreshCallback& on_memory_refresh,
       const OnIdleWakeupsCallback& on_idle_wakeups,
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       const OnOpenFdCountCallback& on_open_fd_count,
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       const OnProcessPriorityCallback& on_process_priority);
 
   // Refreshes the expensive process' stats (CPU usage, memory usage, and idle
@@ -60,9 +60,9 @@ class TaskGroupSampler : public base::RefCountedThread
   double RefreshCpuUsage();
   int64_t RefreshSwappedMem();
   int RefreshIdleWakeupsPerSecond();
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   int RefreshOpenFdCount();
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   bool RefreshProcessPriority();
 
   // The process that holds the handle that we own so that we can use it for
@@ -84,9 +84,9 @@ class TaskGroupSampler : public base::RefCountedThread
   const OnCpuRefreshCallback on_cpu_refresh_callback_;
   const OnSwappedMemRefreshCallback on_swapped_mem_refresh_callback_;
   const OnIdleWakeupsCallback on_idle_wakeups_callback_;
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   const OnOpenFdCountCallback on_open_fd_count_callback_;
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   const OnProcessPriorityCallback on_process_priority_callback_;
 
   // To assert we're running on the correct thread.
