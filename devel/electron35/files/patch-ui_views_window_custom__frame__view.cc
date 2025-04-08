--- ui/views/window/custom_frame_view.cc.orig	2025-03-24 20:50:14 UTC
+++ ui/views/window/custom_frame_view.cc
@@ -279,7 +279,7 @@ int CustomFrameView::CaptionButtonY() const {
 int CustomFrameView::CaptionButtonY() const {
   // Maximized buttons start at window top so that even if their images aren't
   // drawn flush with the screen edge, they still obey Fitts' Law.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
