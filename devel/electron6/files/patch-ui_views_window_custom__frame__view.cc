--- ui/views/window/custom_frame_view.cc.orig	2019-09-10 11:14:40 UTC
+++ ui/views/window/custom_frame_view.cc
@@ -291,7 +291,7 @@ int CustomFrameView::NonClientTopBorderHeight() const 
 int CustomFrameView::CaptionButtonY() const {
   // Maximized buttons start at window top so that even if their images aren't
   // drawn flush with the screen edge, they still obey Fitts' Law.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
