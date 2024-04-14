--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h.orig	2024-02-21 00:20:37 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h
@@ -26,7 +26,7 @@
 #include "ui/views/controls/image_view.h"
 #include "ui/views/widget/widget_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/window_frame_provider.h"
 #endif
 
@@ -34,7 +34,7 @@
 // parent window, so to prevent cutting off important dialogs we resize the
 // picture-in-picture window to fit them. While ChromeOS Ash also uses Aura, it
 // does not have this issue so we do not resize on ChromeOS Ash.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #define RESIZE_DOCUMENT_PICTURE_IN_PICTURE_TO_DIALOG 1
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)
@@ -100,7 +100,7 @@ class PictureInPictureBrowserFrameView
   void Layout() override;
   void AddedToWidget() override;
   void RemovedFromWidget() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gfx::Insets MirroredFrameBorderInsets() const override;
   gfx::Insets GetInputInsets() const override;
   SkRRect GetRestoredClipRegion() const override;
@@ -194,7 +194,7 @@ class PictureInPictureBrowserFrameView
   // Returns true if there's an overlay view that's currently shown.
   bool IsOverlayViewVisible() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Sets the window frame provider so that it will be used for drawing.
   void SetWindowFrameProvider(ui::WindowFrameProvider* window_frame_provider);
 
@@ -366,7 +366,7 @@ class PictureInPictureBrowserFrameView
   // `top_bar_color_animation_`.
   std::optional<SkColor> current_foreground_color_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Used to draw window frame borders and shadow on Linux when GTK theme is
   // enabled.
   raw_ptr<ui::WindowFrameProvider> window_frame_provider_ = nullptr;
