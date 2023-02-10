--- chrome/browser/task_manager/sampling/task_group_sampler.h.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/task_manager/sampling/task_group_sampler.h
@@ -31,7 +31,7 @@ class TaskGroupSampler : public base::RefCountedThread
   using OnCpuRefreshCallback = base::RepeatingCallback<void(double)>;
   using OnSwappedMemRefreshCallback = base::RepeatingCallback<void(int64_t)>;
   using OnIdleWakeupsCallback = base::RepeatingCallback<void(int)>;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   using OnOpenFdCountCallback = base::RepeatingCallback<void(int)>;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
   using OnProcessPriorityCallback = base::RepeatingCallback<void(bool)>;
@@ -42,7 +42,7 @@ class TaskGroupSampler : public base::RefCountedThread
       const OnCpuRefreshCallback& on_cpu_refresh,
       const OnSwappedMemRefreshCallback& on_memory_refresh,
       const OnIdleWakeupsCallback& on_idle_wakeups,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       const OnOpenFdCountCallback& on_open_fd_count,
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
       const OnProcessPriorityCallback& on_process_priority);
@@ -62,7 +62,7 @@ class TaskGroupSampler : public base::RefCountedThread
   double RefreshCpuUsage();
   int64_t RefreshSwappedMem();
   int RefreshIdleWakeupsPerSecond();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   int RefreshOpenFdCount();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
   bool RefreshProcessPriority();
@@ -86,7 +86,7 @@ class TaskGroupSampler : public base::RefCountedThread
   const OnCpuRefreshCallback on_cpu_refresh_callback_;
   const OnSwappedMemRefreshCallback on_swapped_mem_refresh_callback_;
   const OnIdleWakeupsCallback on_idle_wakeups_callback_;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   const OnOpenFdCountCallback on_open_fd_count_callback_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
   const OnProcessPriorityCallback on_process_priority_callback_;
