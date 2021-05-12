--- chrome/browser/web_applications/components/web_app_file_handler_registration.h.orig	2021-01-07 00:36:25 UTC
+++ chrome/browser/web_applications/components/web_app_file_handler_registration.h
@@ -38,7 +38,7 @@ void RegisterFileHandlersWithOs(const AppId& app_id,
 // If a shim app was required, also removes the shim app.
 void UnregisterFileHandlersWithOs(const AppId& app_id, Profile* profile);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 using RegisterMimeTypesOnLinuxCallback =
     base::OnceCallback<bool(base::FilePath profile_path,
                             std::string file_contents)>;
