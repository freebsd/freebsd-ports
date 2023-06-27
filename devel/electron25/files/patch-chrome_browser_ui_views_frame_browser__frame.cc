--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2023-05-25 00:41:45 UTC
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -51,7 +51,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/screen.h"
 #include "ui/linux/linux_ui.h"
 #endif
@@ -59,7 +59,7 @@
 namespace {
 
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
@@ -298,7 +298,7 @@ void BrowserFrame::OnNativeWidgetWorkspaceChanged() {
   chrome::SaveWindowWorkspace(browser_view_->browser(), GetWorkspace());
   chrome::SaveWindowVisibleOnAllWorkspaces(browser_view_->browser(),
                                            IsVisibleOnAllWorkspaces());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If the window was sent to a different workspace, prioritize it if
   // it was sent to the current workspace and deprioritize it
   // otherwise.  This is done by MoveBrowsersInWorkspaceToFront()
@@ -456,7 +456,7 @@ void BrowserFrame::SelectNativeTheme() {
     return;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const auto* linux_ui_theme =
       ui::LinuxUiTheme::GetForWindow(GetNativeWindow());
   // Ignore the system theme for web apps with window-controls-overlay as the
@@ -473,7 +473,7 @@ void BrowserFrame::SelectNativeTheme() {
 bool BrowserFrame::RegenerateFrameOnThemeChange(
     BrowserThemeChangeType theme_change_type) {
   bool need_regenerate = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // System and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   need_regenerate = true;
