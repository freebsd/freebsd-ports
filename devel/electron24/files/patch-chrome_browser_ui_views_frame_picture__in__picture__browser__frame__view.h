--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h.orig	2023-03-30 00:33:44 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h
@@ -20,7 +20,7 @@
 #include "ui/views/controls/image_view.h"
 #include "ui/views/widget/widget_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/window_frame_provider.h"
 #endif
 
@@ -78,7 +78,7 @@ class PictureInPictureBrowserFrameView
   void Layout() override;
   void AddedToWidget() override;
   void RemovedFromWidget() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gfx::Insets MirroredFrameBorderInsets() const override;
   gfx::Insets GetInputInsets() const override;
   SkRRect GetRestoredClipRegion() const override;
@@ -159,7 +159,7 @@ class PictureInPictureBrowserFrameView
   // Called when mouse entered or exited the pip window.
   void OnMouseEnteredOrExitedWindow(bool entered);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Sets the window frame provider so that it will be used for drawing.
   void SetWindowFrameProvider(ui::WindowFrameProvider* window_frame_provider);
 
@@ -222,7 +222,7 @@ class PictureInPictureBrowserFrameView
   gfx::MultiAnimation show_close_button_animation_;
   gfx::MultiAnimation hide_close_button_animation_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Used to draw window frame borders and shadow on Linux when GTK theme is
   // enabled.
   raw_ptr<ui::WindowFrameProvider> window_frame_provider_ = nullptr;
