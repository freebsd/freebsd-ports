--- electron/shell/browser/electron_browser_main_parts.h.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/browser/electron_browser_main_parts.h
@@ -124,7 +124,7 @@ class ElectronBrowserMainParts : public content::Brows
       const scoped_refptr<base::SingleThreadTaskRunner>& task_runner);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void DetectOzonePlatform();
 #endif
 
@@ -146,7 +146,7 @@ class ElectronBrowserMainParts : public content::Brows
   std::unique_ptr<display::Screen> screen_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ui::DarkModeManagerLinux> dark_mode_manager_;
   std::unique_ptr<ui::LinuxUiGetter> linux_ui_getter_;
 #endif
