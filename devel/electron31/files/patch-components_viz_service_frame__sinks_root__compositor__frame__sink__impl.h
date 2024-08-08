--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2024-04-15 20:33:57 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -209,7 +209,7 @@ class VIZ_SERVICE_EXPORT RootCompositorFrameSinkImpl
   // See comments on `EvictionHandler`.
   EvictionHandler eviction_handler_;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
