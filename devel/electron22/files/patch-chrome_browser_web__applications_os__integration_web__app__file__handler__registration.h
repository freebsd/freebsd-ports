--- chrome/browser/web_applications/os_integration/web_app_file_handler_registration.h.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/web_applications/os_integration/web_app_file_handler_registration.h
@@ -45,7 +45,7 @@ void UnregisterFileHandlersWithOs(const AppId& app_id,
                                   Profile* profile,
                                   ResultCallback callback);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Exposed for testing purposes. Register the set of
 // MIME-type-to-file-extensions mappings corresponding to |file_handlers|. File
 // I/O and a a callout to the Linux shell are performed asynchronously.
