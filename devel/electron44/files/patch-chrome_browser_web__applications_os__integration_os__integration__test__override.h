--- chrome/browser/web_applications/os_integration/os_integration_test_override.h.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/web_applications/os_integration/os_integration_test_override.h
@@ -103,7 +103,7 @@ class OsIntegrationTestOverride
   virtual base::FilePath chrome_apps_folder() = 0;
   virtual void EnableOrDisablePathOnLogin(const base::FilePath& file_path,
                                           bool enable_on_login) = 0;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual base::Environment* environment() = 0;
 #endif
 
