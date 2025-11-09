--- ui/ozone/platform/x11/x11_screen_ozone.cc.orig	2025-03-24 20:50:14 UTC
+++ ui/ozone/platform/x11/x11_screen_ozone.cc
@@ -22,7 +22,7 @@
 #include "ui/ozone/platform/x11/x11_window.h"
 #include "ui/ozone/platform/x11/x11_window_manager.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -97,7 +97,7 @@ X11ScreenOzone::X11ScreenOzone()
       window_manager_(X11WindowManager::GetInstance()),
       x11_display_manager_(std::make_unique<XDisplayManager>(this)) {
   DCHECK(window_manager_);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     display_scale_factor_observer_.Observe(linux_ui);
   }
@@ -267,7 +267,7 @@ void X11ScreenOzone::OnEvent(const x11::Event& xev) {
   x11_display_manager_->OnEvent(xev);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void X11ScreenOzone::OnDeviceScaleFactorChanged() {
   x11_display_manager_->DispatchDelayedDisplayListUpdate();
 }
