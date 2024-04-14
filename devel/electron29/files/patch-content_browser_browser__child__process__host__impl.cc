--- content/browser/browser_child_process_host_impl.cc.orig	2024-02-21 00:20:44 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -326,6 +326,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
@@ -635,7 +636,7 @@ void BrowserChildProcessHostImpl::OnProcessLaunched() 
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
