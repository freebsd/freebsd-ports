--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2025-06-30 07:04:30 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -234,7 +234,7 @@ class VIZ_SERVICE_EXPORT RootCompositorFrameSinkImpl
   base::TimeDelta preferred_frame_interval_ =
       FrameRateDecider::UnspecifiedFrameInterval();
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
