--- ui/views/test/ui_controls_factory_desktop_aura_ozone.cc.orig	2022-05-25 04:01:58 UTC
+++ ui/views/test/ui_controls_factory_desktop_aura_ozone.cc
@@ -25,7 +25,7 @@
 #include "ui/ozone/public/ozone_ui_controls_test_helper.h"
 #include "ui/views/test/test_desktop_screen_ozone.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #else
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_platform.h"
@@ -157,7 +157,7 @@ class UIControlsDesktopOzone : public UIControlsAura {
 
  private:
   aura::Window* RootWindowForPoint(const gfx::Point& point) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     // Most interactive_ui_tests run inside of the aura_test_helper
     // environment. This means that we can't rely on display::Screen and several
     // other things to work properly. Therefore we hack around this by
