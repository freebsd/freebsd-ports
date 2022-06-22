--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2022-05-19 05:17:39 UTC
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -49,11 +49,11 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "ui/display/screen.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -62,7 +62,7 @@ namespace {
 bool IsUsingGtkTheme(Profile* profile) {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
@@ -268,7 +268,7 @@ void BrowserFrame::OnNativeWidgetWorkspaceChanged() {
                                            IsVisibleOnAllWorkspaces());
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // If the window was sent to a different workspace, prioritize it if
   // it was sent to the current workspace and deprioritize it
   // otherwise.  This is done by MoveBrowsersInWorkspaceToFront()
@@ -381,7 +381,7 @@ void BrowserFrame::SelectNativeTheme() {
     return;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const views::LinuxUI* linux_ui = views::LinuxUI::instance();
   // Ignore GTK+ for web apps with window-controls-overlay as the
   // display_override so the web contents can blend with the overlay by using
@@ -400,7 +400,7 @@ bool BrowserFrame::RegenerateFrameOnThemeChange(
   bool need_regenerate = false;
   // TODO(crbug.com/1052397): Revisit the macro expression once build flag
   // switch of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // GTK and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   need_regenerate = true;
