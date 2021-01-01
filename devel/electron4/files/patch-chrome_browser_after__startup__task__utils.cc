--- chrome/browser/after_startup_task_utils.cc.orig	2019-03-15 06:37:01 UTC
+++ chrome/browser/after_startup_task_utils.cc
@@ -105,7 +105,7 @@ void QueueTask(std::unique_ptr<AfterStartupTask> queue
 
 void SetBrowserStartupIsComplete() {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // CurrentProcessInfo::CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::CurrentProcessInfo::CreationTime();
