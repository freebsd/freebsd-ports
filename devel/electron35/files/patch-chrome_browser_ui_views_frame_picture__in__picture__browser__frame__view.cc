--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc
@@ -62,7 +62,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_paint_utils_linux.h"
@@ -83,7 +83,7 @@ constexpr int kTopControlsHeight = 34;
 // The height of the controls bar at the top of the window.
 constexpr int kTopControlsHeight = 34;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Frame border when window shadow is not drawn.
 constexpr int kFrameBorderThickness = 4;
 #endif
@@ -178,7 +178,7 @@ class WindowEventObserver : public ui::EventObserver {
 
     gfx::Rect input_bounds = pip_browser_frame_view_->GetLocalBounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Calculate input bounds for Linux. This is needed because the input bounds
     // is not necessary the same as the local bounds on Linux.
     if (pip_browser_frame_view_->ShouldDrawFrameShadow()) {
@@ -649,7 +649,7 @@ PictureInPictureBrowserFrameView::PictureInPictureBrow
         AddChildView(std::move(auto_pip_setting_overlay));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* profile = browser_view->browser()->profile();
   auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile);
   auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
@@ -873,7 +873,7 @@ void PictureInPictureBrowserFrameView::OnThemeChanged(
     view->SetIconColor(color_provider->GetColor(kColorPipWindowForeground));
   }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // On Linux the top bar background will be drawn in OnPaint().
   top_bar_container_view_->SetBackground(views::CreateSolidBackground(
       color_provider->GetColor(kColorPipWindowTopBarBackground)));
@@ -962,7 +962,7 @@ void PictureInPictureBrowserFrameView::RemovedFromWidg
   BrowserNonClientFrameView::RemovedFromWidget();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 gfx::Insets
 PictureInPictureBrowserFrameView::RestoredMirroredFrameBorderInsets() const {
   auto border = FrameBorderInsets();
@@ -1253,7 +1253,7 @@ void PictureInPictureBrowserFrameView::OnPaint(gfx::Ca
 // views::View implementations:
 
 void PictureInPictureBrowserFrameView::OnPaint(gfx::Canvas* canvas) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Draw the PiP window frame borders and shadows, including the top bar
   // background.
   if (window_frame_provider_) {
@@ -1408,7 +1408,7 @@ gfx::Insets PictureInPictureBrowserFrameView::FrameBor
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::FrameBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (window_frame_provider_) {
     const auto insets = window_frame_provider_->GetFrameThicknessDip();
     const bool tiled = frame()->tiled();
@@ -1426,7 +1426,7 @@ gfx::Insets PictureInPictureBrowserFrameView::ResizeBo
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::ResizeBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameBorderInsets();
 #elif !BUILDFLAG(IS_CHROMEOS)
   return gfx::Insets(kResizeBorder);
@@ -1447,7 +1447,7 @@ gfx::Size PictureInPictureBrowserFrameView::GetNonClie
                    top_height + border_thickness.bottom());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool PictureInPictureBrowserFrameView::ShouldDrawFrameShadow() const {
   return static_cast<DesktopBrowserFrameAuraLinux*>(
              frame()->native_browser_frame())
