--- ui/views/window/custom_frame_view.cc.orig	2021-04-14 01:09:40 UTC
+++ ui/views/window/custom_frame_view.cc
@@ -259,7 +259,7 @@ int CustomFrameView::CaptionButtonY() const {
   // drawn flush with the screen edge, they still obey Fitts' Law.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
