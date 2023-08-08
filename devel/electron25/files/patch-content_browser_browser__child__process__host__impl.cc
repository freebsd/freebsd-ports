--- content/browser/browser_child_process_host_impl.cc.orig	2023-05-25 00:41:54 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -319,6 +319,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
