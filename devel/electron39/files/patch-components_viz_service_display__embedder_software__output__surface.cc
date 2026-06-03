--- components/viz/service/display_embedder/software_output_surface.cc.orig	2025-03-24 20:50:14 UTC
+++ components/viz/service/display_embedder/software_output_surface.cc
@@ -115,7 +115,7 @@ void SoftwareOutputSurface::SwapBuffersCallback(base::
   base::TimeTicks now = base::TimeTicks::Now();
   base::TimeDelta interval_to_next_refresh =
       now.SnappedToNextTick(refresh_timebase_, refresh_interval_) - now;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (needs_swap_size_notifications_)
     client_->DidSwapWithSize(pixel_size);
 #endif
@@ -142,7 +142,7 @@ gfx::OverlayTransform SoftwareOutputSurface::GetDispla
   return gfx::OVERLAY_TRANSFORM_NONE;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SoftwareOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {
   needs_swap_size_notifications_ = needs_swap_size_notifications;
