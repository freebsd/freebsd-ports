--- ui/views/test/ui_controls_factory_desktop_aura_ozone.cc.orig	2026-06-23 23:37:18 UTC
+++ ui/views/test/ui_controls_factory_desktop_aura_ozone.cc
@@ -241,7 +241,7 @@ bool SendMouseClick(MouseButton type, gfx::NativeWindo
                          window_hint);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ForceUseScreenCoordinatesOnce() {
   g_ozone_ui_controls_test_helper->ForceUseScreenCoordinatesOnce();
