--- chrome/browser/accessibility/page_colors.cc.orig	2024-08-14 20:54:31 UTC
+++ chrome/browser/accessibility/page_colors.cc
@@ -12,7 +12,7 @@
 #include "components/sync_preferences/pref_service_syncable.h"
 #include "ui/native_theme/native_theme.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_factory.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -55,7 +55,7 @@ void PageColors::OnPageColorsChanged() {
 
 void PageColors::OnPageColorsChanged() {
   auto* native_theme = ui::NativeTheme::GetInstanceForNativeUi();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Allow the Linux native theme to update its state for page colors.
   if (auto* linux_ui_theme = ui::GetDefaultLinuxUiTheme()) {
     if (auto* linux_native_theme = linux_ui_theme->GetNativeTheme()) {
