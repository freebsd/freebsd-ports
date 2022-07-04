--- electron/shell/browser/native_window_views.cc.orig	2022-06-30 19:37:49 UTC
+++ electron/shell/browser/native_window_views.cc
@@ -43,7 +43,7 @@
 #include "ui/wm/core/shadow_types.h"
 #include "ui/wm/core/window_util.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/strings/string_util.h"
 #include "shell/browser/browser.h"
 #include "shell/browser/linux/unity_service.h"
@@ -264,7 +264,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
     params.parent = parent->GetNativeWindow();
 
   params.native_widget = new ElectronDesktopNativeWidgetAura(this);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::string name = Browser::Get()->GetName();
   // Set WM_WINDOW_ROLE.
   params.wm_role_name = "browser-window";
@@ -287,7 +287,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
   std::string window_type;
   options.Get(options::kType, &window_type);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Set _GTK_THEME_VARIANT to dark if we have "dark-theme" option set.
   bool use_dark_theme = false;
   if (options.Get(options::kDarkTheme, &use_dark_theme) && use_dark_theme) {
@@ -393,7 +393,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
   if (window)
     window->AddPreTargetHandler(this);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On linux after the widget is initialized we might have to force set the
   // bounds if the bounds are smaller than the current display
   SetBounds(gfx::Rect(GetPosition(), bounds.size()), false);
@@ -536,7 +536,7 @@ bool NativeWindowViews::IsVisible() {
 bool NativeWindowViews::IsEnabled() {
 #if defined(OS_WIN)
   return ::IsWindowEnabled(GetAcceleratedWidget());
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #if defined(USE_OZONE_PLATFORM_X11)
   if (IsX11())
     return !event_disabler_.get();
@@ -594,7 +594,7 @@ void NativeWindowViews::SetEnabledInternal(bool enable
 #endif
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void NativeWindowViews::Maximize() {
   if (IsVisible()) {
     widget()->Maximize();
@@ -722,7 +722,7 @@ void NativeWindowViews::SetBounds(const gfx::Rect& bou
   }
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // On Linux and Windows the minimum and maximum size should be updated with
   // window size when window is not resizable.
   if (!resizable_) {
@@ -954,7 +954,7 @@ bool NativeWindowViews::IsClosable() {
     return false;
   }
   return !(info.fState & MFS_DISABLED);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return true;
 #endif
 }
@@ -1346,7 +1346,7 @@ void NativeWindowViews::SetProgressBar(double progress
                                        NativeWindow::ProgressState state) {
 #if defined(OS_WIN)
   taskbar_host_.SetProgressBar(GetAcceleratedWidget(), progress, state);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (unity::IsRunning()) {
     unity::SetProgressFraction(progress);
   }
@@ -1408,7 +1408,7 @@ content::DesktopMediaID NativeWindowViews::GetDesktopM
 #if defined(OS_WIN)
   window_handle =
       reinterpret_cast<content::DesktopMediaID::Id>(accelerated_widget);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   window_handle = static_cast<uint32_t>(accelerated_widget);
 #endif
   aura::WindowTreeHost* const host =
@@ -1511,7 +1511,7 @@ void NativeWindowViews::SetIcon(HICON window_icon, HIC
   SendMessage(hwnd, WM_SETICON, ICON_BIG,
               reinterpret_cast<LPARAM>(app_icon_.get()));
 }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 void NativeWindowViews::SetIcon(const gfx::ImageSkia& icon) {
   auto* tree_host = views::DesktopWindowTreeHostLinux::GetHostForWidget(
       GetAcceleratedWidget());
@@ -1581,7 +1581,7 @@ bool NativeWindowViews::CanMaximize() const {
 bool NativeWindowViews::CanMinimize() const {
 #if defined(OS_WIN)
   return minimizable_;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return true;
 #endif
 }
@@ -1655,7 +1655,7 @@ void NativeWindowViews::HandleKeyboardEvent(
   if (widget_destroyed_)
     return;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (event.windows_key_code == ui::VKEY_BROWSER_BACK)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event.windows_key_code == ui::VKEY_BROWSER_FORWARD)
@@ -1674,7 +1674,7 @@ void NativeWindowViews::OnMouseEvent(ui::MouseEvent* e
   // Alt+Click should not toggle menu bar.
   root_view_->ResetAltState();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (event->changed_button_flags() == ui::EF_BACK_MOUSE_BUTTON)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event->changed_button_flags() == ui::EF_FORWARD_MOUSE_BUTTON)
