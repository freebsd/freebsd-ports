--- apps/ui/views/app_window_frame_view.cc.orig	2025-04-22 20:15:27 UTC
+++ apps/ui/views/app_window_frame_view.cc
@@ -146,7 +146,7 @@ gfx::Rect AppWindowFrameView::GetWindowBoundsForClient
 gfx::Rect AppWindowFrameView::GetWindowBoundsForClientBounds(
     const gfx::Rect& client_bounds) const {
   gfx::Rect window_bounds = client_bounds;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Get the difference between the widget's client area bounds and window
   // bounds, and grow |window_bounds| by that amount.
   gfx::Insets native_frame_insets =
