--- electron/shell/browser/browser.h.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/browser/browser.h
@@ -186,7 +186,7 @@ class Browser : public WindowListObserver {
 
 #endif  // defined(OS_MACOSX)
 
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   void ShowAboutPanel();
   void SetAboutPanelOptions(const base::DictionaryValue& options);
 #endif
@@ -219,10 +219,10 @@ class Browser : public WindowListObserver {
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
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::Value about_panel_options_;
 #elif defined(OS_MACOSX)
   base::DictionaryValue about_panel_options_;
