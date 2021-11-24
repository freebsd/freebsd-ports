--- electron/shell/browser/browser.h.orig	2021-10-27 21:25:28 UTC
+++ electron/shell/browser/browser.h
@@ -102,7 +102,7 @@ class Browser : public WindowListObserver {
 
   std::u16string GetApplicationNameForProtocol(const GURL& url);
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   // get the name, icon and path for an application
   v8::Local<v8::Promise> GetApplicationInfoForProtocol(v8::Isolate* isolate,
                                                        const GURL& url);
@@ -260,10 +260,10 @@ class Browser : public WindowListObserver {
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
@@ -360,7 +360,7 @@ class Browser : public WindowListObserver {
   base::Time last_dock_show_;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   base::Value about_panel_options_;
 #elif defined(OS_MAC)
   base::DictionaryValue about_panel_options_;
