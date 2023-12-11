--- content/browser/browser_child_process_host_impl.cc.orig	2023-08-10 01:48:43 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -321,6 +321,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
