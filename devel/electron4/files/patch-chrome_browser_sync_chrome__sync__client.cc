--- chrome/browser/sync/chrome_sync_client.cc.orig	2019-03-15 06:37:06 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -389,14 +389,14 @@ ChromeSyncClient::CreateDataTypeControllers(
       BrowserThread::GetTaskRunnerForThread(BrowserThread::UI)));
 #endif  // BUILDFLAG(ENABLE_APP_LIST)
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     controllers.push_back(std::make_unique<AsyncDirectoryTypeController>(
         syncer::DICTIONARY, error_callback, this, syncer::GROUP_UI,
         BrowserThread::GetTaskRunnerForThread(BrowserThread::UI)));
   }
-#endif  // defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   if (base::CommandLine::ForCurrentProcess()->HasSwitch(
