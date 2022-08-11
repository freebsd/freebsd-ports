--- ui/aura/screen_ozone.cc.orig	2022-05-25 04:01:57 UTC
+++ ui/aura/screen_ozone.cc
@@ -99,7 +99,7 @@ display::Display ScreenOzone::GetPrimaryDisplay() cons
   return platform_screen_->GetPrimaryDisplay();
 }
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool ScreenOzone::SetScreenSaverSuspended(bool suspend) {
   return platform_screen_->SetScreenSaverSuspended(suspend);
 }
