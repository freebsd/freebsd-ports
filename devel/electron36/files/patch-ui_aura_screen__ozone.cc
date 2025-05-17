--- ui/aura/screen_ozone.cc.orig	2025-01-27 17:37:37 UTC
+++ ui/aura/screen_ozone.cc
@@ -107,7 +107,7 @@ display::Display ScreenOzone::GetPrimaryDisplay() cons
   return platform_screen_->GetPrimaryDisplay();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 ScreenOzone::ScreenSaverSuspenderOzone::ScreenSaverSuspenderOzone(
     std::unique_ptr<ui::PlatformScreen::PlatformScreenSaverSuspender> suspender)
     : suspender_(std::move(suspender)) {}
