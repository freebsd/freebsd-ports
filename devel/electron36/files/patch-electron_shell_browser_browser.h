--- electron/shell/browser/browser.h.orig	2025-08-14 14:48:00 UTC
+++ electron/shell/browser/browser.h
@@ -147,7 +147,7 @@ class Browser : private WindowListObserver {
 
   std::u16string GetApplicationNameForProtocol(const GURL& url);
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // get the name, icon and path for an application
   v8::Local<v8::Promise> GetApplicationInfoForProtocol(v8::Isolate* isolate,
                                                        const GURL& url);
@@ -275,10 +275,10 @@ class Browser : private WindowListObserver {
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
