--- electron/shell/browser/ui/views/electron_views_delegate.cc.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/ui/views/electron_views_delegate.cc
@@ -9,7 +9,7 @@
 #include "ui/views/widget/desktop_aura/desktop_native_widget_aura.h"
 #include "ui/views/widget/native_widget_aura.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "ui/views/linux_ui/linux_ui.h"
@@ -17,7 +17,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsDesktopEnvironmentUnity() {
   auto env = base::Environment::Create();
   base::nix::DesktopEnvironment desktop_env =
@@ -53,7 +53,7 @@ void ViewsDelegate::NotifyMenuItemFocused(const std::u
                                           int item_count,
                                           bool has_submenu) {}
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
@@ -85,7 +85,7 @@ void ViewsDelegate::OnBeforeWidgetInit(
 }
 
 bool ViewsDelegate::WindowManagerProvidesTitleBar(bool maximized) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Ubuntu Unity, the system always provides a title bar for maximized
   // windows.
   if (!maximized)
