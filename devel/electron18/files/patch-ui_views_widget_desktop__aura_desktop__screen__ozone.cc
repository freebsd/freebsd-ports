--- ui/views/widget/desktop_aura/desktop_screen_ozone.cc.orig	2022-05-19 05:18:02 UTC
+++ ui/views/widget/desktop_aura/desktop_screen_ozone.cc
@@ -25,7 +25,7 @@ gfx::NativeWindow DesktopScreenOzone::GetNativeWindowF
       widget);
 }
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 std::unique_ptr<display::Screen> CreateDesktopScreen() {
   auto screen = std::make_unique<aura::ScreenOzone>();
   screen->Initialize();
