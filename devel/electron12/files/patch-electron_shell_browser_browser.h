--- electron/shell/browser/browser.h.orig	2021-04-20 23:32:33 UTC
+++ electron/shell/browser/browser.h
@@ -101,7 +101,7 @@ class Browser : public WindowListObserver {
 
   base::string16 GetApplicationNameForProtocol(const GURL& url);
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   // get the name, icon and path for an application
   v8::Local<v8::Promise> GetApplicationInfoForProtocol(v8::Isolate* isolate,
                                                        const GURL& url);
@@ -259,10 +259,10 @@ class Browser : public WindowListObserver {
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
@@ -359,7 +359,7 @@ class Browser : public WindowListObserver {
   base::Time last_dock_show_;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   base::Value about_panel_options_;
 #elif defined(OS_MAC)
   base::DictionaryValue about_panel_options_;
