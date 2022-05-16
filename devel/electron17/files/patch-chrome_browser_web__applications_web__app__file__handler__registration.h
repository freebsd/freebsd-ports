--- chrome/browser/web_applications/web_app_file_handler_registration.h.orig	2022-05-11 07:16:49 UTC
+++ chrome/browser/web_applications/web_app_file_handler_registration.h
@@ -44,7 +44,7 @@ void UnregisterFileHandlersWithOs(const AppId& app_id,
                                   Profile* profile,
                                   ResultCallback callback);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Exposed for testing purposes. Register the set of
 // MIME-type-to-file-extensions mappings corresponding to |file_handlers|. File
 // I/O and a a callout to the Linux shell are performed asynchronously.
