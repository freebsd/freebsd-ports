--- electron/atom/browser/ui/views/atom_views_delegate.cc.orig	2019-11-20 23:42:47 UTC
+++ electron/atom/browser/ui/views/atom_views_delegate.cc
@@ -9,7 +9,7 @@
 #include "ui/views/widget/desktop_aura/desktop_native_widget_aura.h"
 #include "ui/views/widget/native_widget_aura.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "ui/views/linux_ui/linux_ui.h"
@@ -17,7 +17,7 @@
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool IsDesktopEnvironmentUnity() {
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   base::nix::DesktopEnvironment desktop_env =
@@ -53,7 +53,7 @@ void ViewsDelegate::NotifyMenuItemFocused(const base::
                                           int item_count,
                                           bool has_submenu) {}
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return NULL;
 }
@@ -85,7 +85,7 @@ void ViewsDelegate::OnBeforeWidgetInit(
 }
 
 bool ViewsDelegate::WindowManagerProvidesTitleBar(bool maximized) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Ubuntu Unity, the system always provides a title bar for maximized
   // windows.
   if (!maximized)
