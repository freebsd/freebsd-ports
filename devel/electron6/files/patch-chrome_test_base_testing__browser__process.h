--- chrome/test/base/testing_browser_process.h.orig	2019-09-10 11:13:47 UTC
+++ chrome/test/base/testing_browser_process.h
@@ -120,8 +120,8 @@ class TestingBrowserProcess : public BrowserProcess {
   DownloadRequestLimiter* download_request_limiter() override;
   StartupData* startup_data() override;
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
-  void StartAutoupdateTimer() override {}
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
+  void StartAutoupdateTimer() /*override*/ {}
 #endif
 
   net_log::ChromeNetLog* net_log() override;
