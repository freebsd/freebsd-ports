--- chrome/browser/web_applications/os_integration/web_app_shortcut.h.orig	2022-10-24 13:33:33 UTC
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.h
@@ -21,7 +21,7 @@
 #include "ui/gfx/image/image_family.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/os_integration/web_app_shortcut_linux.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -35,7 +35,7 @@ class ImageSkia;
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 struct LinuxFileRegistration {
   std::string xdg_command;
   std::string file_contents;
@@ -85,7 +85,7 @@ struct ShortcutOverrideForTesting
 #elif BUILDFLAG(IS_MAC)
   base::ScopedTempDir chrome_apps_folder;
   std::map<base::FilePath, bool> startup_enabled;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedTempDir desktop;
   base::ScopedTempDir startup;
   std::vector<LinuxFileRegistration> linux_file_registration;
@@ -132,7 +132,7 @@ struct ShortcutInfo {
   std::set<std::string> file_handler_extensions;
   std::set<std::string> file_handler_mime_types;
   std::set<std::string> protocol_handlers;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::set<DesktopActionInfo> actions;
 #endif  // BUILDFLAG(IS_LINUX)
 
