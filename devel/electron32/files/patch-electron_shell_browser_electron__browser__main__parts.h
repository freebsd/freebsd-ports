--- electron/shell/browser/electron_browser_main_parts.h.orig	2023-10-20 08:29:17 UTC
+++ electron/shell/browser/electron_browser_main_parts.h
@@ -119,7 +119,7 @@ class ElectronBrowserMainParts : public content::Brows
       const scoped_refptr<base::SingleThreadTaskRunner>& task_runner);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void DetectOzonePlatform();
 #endif
 
@@ -141,7 +141,7 @@ class ElectronBrowserMainParts : public content::Brows
   std::unique_ptr<display::Screen> screen_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ui::DarkModeManagerLinux> dark_mode_manager_;
   std::unique_ptr<ui::LinuxUiGetter> linux_ui_getter_;
 #endif
