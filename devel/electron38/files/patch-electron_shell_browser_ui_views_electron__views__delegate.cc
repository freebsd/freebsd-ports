--- electron/shell/browser/ui/views/electron_views_delegate.cc.orig	2025-11-13 22:57:06 UTC
+++ electron/shell/browser/ui/views/electron_views_delegate.cc
@@ -10,7 +10,7 @@
 #include "ui/views/widget/native_widget_aura.h"
 #include "ui/views/window/default_frame_view.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "ui/linux/linux_ui.h"
@@ -18,7 +18,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsDesktopEnvironmentUnity() {
   auto env = base::Environment::Create();
   base::nix::DesktopEnvironment desktop_env =
@@ -55,7 +55,7 @@ void ViewsDelegate::NotifyMenuItemFocused(const std::u
                                           int item_count,
                                           bool has_submenu) {}
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
@@ -83,7 +83,7 @@ bool ViewsDelegate::WindowManagerProvidesTitleBar(bool
 }
 
 bool ViewsDelegate::WindowManagerProvidesTitleBar(bool maximized) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Ubuntu Unity, the system always provides a title bar for maximized
   // windows.
   if (!maximized)
