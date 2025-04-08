--- chrome/browser/web_applications/test/os_integration_test_override_impl.h.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/web_applications/test/os_integration_test_override_impl.h
@@ -40,7 +40,7 @@ namespace web_app {
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 struct LinuxFileRegistration {
   base::FilePath file_name;
   std::string xdg_command;
@@ -122,7 +122,7 @@ class OsIntegrationTestOverrideImpl : public OsIntegra
   bool DeleteApplicationMenuDirOnWin();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool DeleteDesktopDirOnLinux();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -250,7 +250,7 @@ class OsIntegrationTestOverrideImpl : public OsIntegra
   base::FilePath chrome_apps_folder() override;
   void EnableOrDisablePathOnLogin(const base::FilePath& file_path,
                                   bool enable_on_login) override;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath desktop();
   base::FilePath startup();
   base::FilePath applications();
@@ -323,7 +323,7 @@ class OsIntegrationTestOverrideImpl : public OsIntegra
   base::ScopedTempDir chrome_apps_folder_;
   std::map<base::FilePath, bool> startup_enabled_;
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedTempDir desktop_;
   base::ScopedTempDir startup_;
   base::ScopedTempDir xdg_data_home_dir_;
