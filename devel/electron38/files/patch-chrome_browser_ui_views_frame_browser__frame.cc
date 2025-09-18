--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -53,7 +53,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/screen.h"
 #include "ui/linux/linux_ui.h"
 #endif
@@ -68,7 +68,7 @@ constexpr double kTitlePaddingWidthFraction = 0.1;
 constexpr double kTitlePaddingWidthFraction = 0.1;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // These values are used for Linux/GTK.
 constexpr int kIconTitleSpacing = 4;
 constexpr int kCaptionSpacing = 5;
@@ -98,7 +98,7 @@ bool IsUsingLinuxSystemTheme(Profile* profile) {
 };
 
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
@@ -196,7 +196,7 @@ void BrowserFrame::InitBrowserFrame() {
 
   Init(std::move(params));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SelectNativeTheme();
 #else
   SetNativeTheme(ui::NativeTheme::GetInstanceForNativeUi());
@@ -434,7 +434,7 @@ void BrowserFrame::OnNativeWidgetWorkspaceChanged() {
   chrome::SaveWindowWorkspace(browser_view_->browser(), GetWorkspace());
   chrome::SaveWindowVisibleOnAllWorkspaces(browser_view_->browser(),
                                            IsVisibleOnAllWorkspaces());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If the window was sent to a different workspace, prioritize it if
   // it was sent to the current workspace and deprioritize it
   // otherwise.  This is done by MoveBrowsersInWorkspaceToFront()
@@ -633,7 +633,7 @@ void BrowserFrame::SelectNativeTheme() {
 }
 
 void BrowserFrame::SelectNativeTheme() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use the regular NativeTheme instance if running incognito mode, regardless
   // of system theme (gtk, qt etc).
   ui::NativeTheme* native_theme = ui::NativeTheme::GetInstanceForNativeUi();
@@ -674,7 +674,7 @@ bool BrowserFrame::RegenerateFrameOnThemeChange(
 bool BrowserFrame::RegenerateFrameOnThemeChange(
     BrowserThemeChangeType theme_change_type) {
   bool need_regenerate = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // System and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   need_regenerate = true;
