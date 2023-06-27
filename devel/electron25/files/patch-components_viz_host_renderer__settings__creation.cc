--- components/viz/host/renderer_settings_creation.cc.orig	2023-01-30 07:58:58 UTC
+++ components/viz/host/renderer_settings_creation.cc
@@ -55,7 +55,7 @@ RendererSettings CreateRendererSettings() {
   renderer_settings.partial_swap_enabled =
       !command_line->HasSwitch(switches::kUIDisablePartialSwap);
 
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Simple frame rate throttling only works on macOS and Linux
   renderer_settings.apply_simple_frame_rate_throttling =
       features::IsSimpleFrameRateThrottlingEnabled();
