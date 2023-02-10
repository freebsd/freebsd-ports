--- ui/aura/screen_ozone.h.orig	2022-10-24 13:33:33 UTC
+++ ui/aura/screen_ozone.h
@@ -46,7 +46,7 @@ class AURA_EXPORT ScreenOzone : public display::Screen
   display::Display GetDisplayMatching(
       const gfx::Rect& match_rect) const override;
   display::Display GetPrimaryDisplay() const override;
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<display::Screen::ScreenSaverSuspender> SuspendScreenSaver()
       override;
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
@@ -71,7 +71,7 @@ class AURA_EXPORT ScreenOzone : public display::Screen
   ui::PlatformScreen* platform_screen() { return platform_screen_.get(); }
 
  private:
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   class ScreenSaverSuspenderOzone
       : public display::Screen::ScreenSaverSuspender {
    public:
