--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2021-04-14 01:08:41 UTC
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc
@@ -16,7 +16,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "chrome/browser/ui/views/frame/desktop_linux_browser_frame_view.h"
 #include "chrome/browser/ui/views/frame/desktop_linux_browser_frame_view_layout.h"
 #include "ui/views/linux_ui/linux_ui.h"
@@ -32,7 +32,7 @@ std::unique_ptr<OpaqueBrowserFrameView> CreateOpaqueBr
     BrowserView* browser_view) {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   auto* linux_ui = views::LinuxUI::instance();
   auto* profile = browser_view->browser()->profile();
   auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
