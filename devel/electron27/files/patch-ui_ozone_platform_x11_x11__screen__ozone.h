--- ui/ozone/platform/x11/x11_screen_ozone.h.orig	2023-10-19 19:59:21 UTC
+++ ui/ozone/platform/x11/x11_screen_ozone.h
@@ -61,7 +61,7 @@ class X11ScreenOzone : public PlatformScreen,
   std::string GetCurrentWorkspace() override;
   base::Value::List GetGpuExtraInfo(
       const gfx::GpuExtraInfo& gpu_extra_info) override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetDisplayConfig(const DisplayConfig& display_config) override;
 #endif
 
