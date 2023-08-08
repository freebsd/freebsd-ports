--- chrome/browser/web_applications/os_integration/web_app_shortcut.cc.orig	2022-10-24 13:33:33 UTC
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.cc
@@ -54,7 +54,7 @@ namespace {
 
 #if BUILDFLAG(IS_MAC)
 const int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredIconSizesForShortcut[] = {16, 32, 48, 128, 256, 512};
@@ -207,7 +207,7 @@ ShortcutOverrideForTesting::ShortcutOverrideForTesting
 #elif BUILDFLAG(IS_MAC)
     bool success = chrome_apps_folder.CreateUniqueTempDirUnderPath(base_path);
     DCHECK(success);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool success = desktop.CreateUniqueTempDirUnderPath(base_path);
     DCHECK(success);
     success = startup.CreateUniqueTempDirUnderPath(base_path);
@@ -226,7 +226,7 @@ ShortcutOverrideForTesting::ShortcutOverrideForTesting
 #elif BUILDFLAG(IS_MAC)
     bool success = chrome_apps_folder.CreateUniqueTempDir();
     DCHECK(success);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool success = desktop.CreateUniqueTempDir();
     DCHECK(success);
     success = startup.CreateUniqueTempDir();
@@ -234,7 +234,7 @@ ShortcutOverrideForTesting::ShortcutOverrideForTesting
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto callback =
       base::BindRepeating([](base::FilePath filename, std::string xdg_command,
                              std::string file_contents) {
@@ -267,7 +267,7 @@ ShortcutOverrideForTesting::~ShortcutOverrideForTestin
       }
     }
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reset the file handling callback.
   SetUpdateMimeInfoDatabaseOnLinuxCallbackForTesting(
       UpdateMimeInfoDatabaseOnLinuxCallback());
