--- ui/ozone/public/platform_screen.h.orig	2023-10-19 19:59:21 UTC
+++ ui/ozone/public/platform_screen.h
@@ -15,7 +15,7 @@
 #include "ui/gfx/gpu_extra_info.h"
 #include "ui/gfx/native_widget_types.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -136,7 +136,7 @@ class COMPONENT_EXPORT(OZONE_BASE) PlatformScreen {
   virtual base::Value::List GetGpuExtraInfo(
       const gfx::GpuExtraInfo& gpu_extra_info);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Sets device scale factor received from external sources such as toolkits.
   virtual void SetDisplayConfig(const DisplayConfig& display_config);
 #endif
