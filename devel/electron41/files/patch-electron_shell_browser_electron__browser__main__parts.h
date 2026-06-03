--- electron/shell/browser/electron_browser_main_parts.h.orig	2026-03-31 13:26:31 UTC
+++ electron/shell/browser/electron_browser_main_parts.h
@@ -143,7 +143,7 @@ class ElectronBrowserMainParts : public content::Brows
   std::unique_ptr<display::Screen> screen_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ui::DarkModeManagerLinux> dark_mode_manager_;
   std::unique_ptr<ui::LinuxUiGetter> linux_ui_getter_;
 #endif
