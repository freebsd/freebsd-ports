--- electron/atom/browser/browser.h.orig	2019-09-11 17:30:11 UTC
+++ electron/atom/browser/browser.h
@@ -182,7 +182,7 @@ class Browser : public WindowListObserver {
 
 #endif  // defined(OS_MACOSX)
 
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   void ShowAboutPanel();
   void SetAboutPanelOptions(const base::DictionaryValue& options);
 #endif
@@ -215,10 +215,10 @@ class Browser : public WindowListObserver {
   PCWSTR GetAppUserModelID();
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Whether Unity launcher is running.
   bool IsUnityRunning();
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   // Tell the application to open a file.
   bool OpenFile(const std::string& file_path);
@@ -301,7 +301,7 @@ class Browser : public WindowListObserver {
 
   std::unique_ptr<util::Promise> ready_promise_;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   base::DictionaryValue about_panel_options_;
 #endif
 
