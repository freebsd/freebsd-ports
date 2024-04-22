--- electron/shell/browser/browser.h.orig	2023-04-03 22:25:21 UTC
+++ electron/shell/browser/browser.h
@@ -101,7 +101,7 @@ class Browser : public WindowListObserver {
 
   std::u16string GetApplicationNameForProtocol(const GURL& url);
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // get the name, icon and path for an application
   v8::Local<v8::Promise> GetApplicationInfoForProtocol(v8::Isolate* isolate,
                                                        const GURL& url);
@@ -263,10 +263,10 @@ class Browser : public WindowListObserver {
   PCWSTR GetAppUserModelID();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Whether Unity launcher is running.
   bool IsUnityRunning();
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
   // Tell the application to open a file.
   bool OpenFile(const std::string& file_path);
