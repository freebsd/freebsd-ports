--- ui/ozone/platform/wayland/host/wayland_screen.h.orig	2024-10-16 21:32:40 UTC
+++ ui/ozone/platform/wayland/host/wayland_screen.h
@@ -24,7 +24,7 @@
 #include "ui/ozone/platform/wayland/host/wayland_output.h"
 #include "ui/ozone/public/platform_screen.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #include "ui/linux/device_scale_factor_observer.h"
 #include "ui/linux/linux_ui.h"
@@ -44,7 +44,7 @@ class WaylandScreen : public PlatformScreen
 
 // A PlatformScreen implementation for Wayland.
 class WaylandScreen : public PlatformScreen
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ,
                       public DeviceScaleFactorObserver
 #endif
@@ -96,7 +96,7 @@ class WaylandScreen : public PlatformScreen
   display::TabletState GetTabletState() const override;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // DeviceScaleFactorObserver:
   void OnDeviceScaleFactorChanged() override;
 #endif
@@ -158,7 +158,7 @@ class WaylandScreen : public PlatformScreen
   display::TabletState tablet_state_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   float font_scale_ = 1.0f;
 
   base::ScopedObservation<ui::LinuxUi, DeviceScaleFactorObserver>
