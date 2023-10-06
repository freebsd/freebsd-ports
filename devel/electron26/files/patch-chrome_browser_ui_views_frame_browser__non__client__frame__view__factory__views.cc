--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2023-05-25 00:41:45 UTC
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc
@@ -16,7 +16,7 @@
 #include "chrome/browser/ui/views/frame/browser_frame_view_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_linux_native.h"
@@ -33,7 +33,7 @@ namespace {
 std::unique_ptr<OpaqueBrowserFrameView> CreateOpaqueBrowserFrameView(
     BrowserFrame* frame,
     BrowserView* browser_view) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* profile = browser_view->browser()->profile();
   auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile);
   auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
@@ -81,7 +81,7 @@ std::unique_ptr<BrowserNonClientFrameView> CreateBrows
   if (browser_view->browser()->is_type_picture_in_picture()) {
     auto view =
         std::make_unique<PictureInPictureBrowserFrameView>(frame, browser_view);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto* profile = browser_view->browser()->profile();
     auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile);
     auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
