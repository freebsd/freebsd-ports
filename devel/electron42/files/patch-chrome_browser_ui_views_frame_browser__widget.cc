--- chrome/browser/ui/views/frame/browser_widget.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/ui/views/frame/browser_widget.cc
@@ -52,7 +52,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -86,7 +86,7 @@ bool IsUsingLinuxSystemTheme(ThemeService* theme_servi
 };
 
 bool IsUsingLinuxSystemTheme(ThemeService* theme_service) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return theme_service->UsingSystemTheme();
 #else
   return false;
@@ -209,7 +209,7 @@ void BrowserWidget::InitBrowserWidget() {
 
   Init(std::move(params));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SelectNativeTheme();
 #else
   SetNativeTheme(ui::NativeTheme::GetInstanceForNativeUi());
@@ -535,7 +535,7 @@ void BrowserWidget::SelectNativeTheme() {
 }
 
 void BrowserWidget::SelectNativeTheme() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use the regular NativeTheme instance if running incognito mode, regardless
   // of system theme (gtk, qt etc).
   ui::NativeTheme* native_theme = ui::NativeTheme::GetInstanceForNativeUi();
@@ -576,7 +576,7 @@ bool BrowserWidget::RegenerateFrameOnThemeChange(
 bool BrowserWidget::RegenerateFrameOnThemeChange(
     BrowserThemeChangeType theme_change_type) {
   bool need_regenerate = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // System and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   need_regenerate = true;
