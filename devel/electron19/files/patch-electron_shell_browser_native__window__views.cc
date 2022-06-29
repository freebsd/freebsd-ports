--- electron/shell/browser/native_window_views.cc.orig	2022-06-08 15:30:58 UTC
+++ electron/shell/browser/native_window_views.cc
@@ -43,7 +43,7 @@
 #include "ui/wm/core/shadow_types.h"
 #include "ui/wm/core/window_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_util.h"
 #include "shell/browser/browser.h"
 #include "shell/browser/linux/unity_service.h"
@@ -264,7 +264,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
     params.parent = parent->GetNativeWindow();
 
   params.native_widget = new ElectronDesktopNativeWidgetAura(this);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string name = Browser::Get()->GetName();
   // Set WM_WINDOW_ROLE.
   params.wm_role_name = "browser-window";
@@ -287,7 +287,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
   std::string window_type;
   options.Get(options::kType, &window_type);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set _GTK_THEME_VARIANT to dark if we have "dark-theme" option set.
   bool use_dark_theme = false;
   if (options.Get(options::kDarkTheme, &use_dark_theme) && use_dark_theme) {
@@ -394,7 +394,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
   if (window)
     window->AddPreTargetHandler(this);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On linux after the widget is initialized we might have to force set the
   // bounds if the bounds are smaller than the current display
   SetBounds(gfx::Rect(GetPosition(), bounds.size()), false);
@@ -537,7 +537,7 @@ bool NativeWindowViews::IsVisible() {
 bool NativeWindowViews::IsEnabled() {
 #if BUILDFLAG(IS_WIN)
   return ::IsWindowEnabled(GetAcceleratedWidget());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if defined(USE_OZONE_PLATFORM_X11)
   if (IsX11())
     return !event_disabler_.get();
@@ -595,7 +595,7 @@ void NativeWindowViews::SetEnabledInternal(bool enable
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NativeWindowViews::Maximize() {
   if (IsVisible()) {
     widget()->Maximize();
@@ -723,7 +723,7 @@ void NativeWindowViews::SetBounds(const gfx::Rect& bou
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux and Windows the minimum and maximum size should be updated with
   // window size when window is not resizable.
   if (!resizable_) {
@@ -940,7 +940,7 @@ bool NativeWindowViews::IsClosable() {
     return false;
   }
   return !(info.fState & MFS_DISABLED);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #endif
 }
@@ -1332,7 +1332,7 @@ void NativeWindowViews::SetProgressBar(double progress
                                        NativeWindow::ProgressState state) {
 #if BUILDFLAG(IS_WIN)
   taskbar_host_.SetProgressBar(GetAcceleratedWidget(), progress, state);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (unity::IsRunning()) {
     unity::SetProgressFraction(progress);
   }
@@ -1394,7 +1394,7 @@ content::DesktopMediaID NativeWindowViews::GetDesktopM
 #if BUILDFLAG(IS_WIN)
   window_handle =
       reinterpret_cast<content::DesktopMediaID::Id>(accelerated_widget);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   window_handle = static_cast<uint32_t>(accelerated_widget);
 #endif
   aura::WindowTreeHost* const host =
@@ -1497,7 +1497,7 @@ void NativeWindowViews::SetIcon(HICON window_icon, HIC
   SendMessage(hwnd, WM_SETICON, ICON_BIG,
               reinterpret_cast<LPARAM>(app_icon_.get()));
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NativeWindowViews::SetIcon(const gfx::ImageSkia& icon) {
   auto* tree_host = views::DesktopWindowTreeHostLinux::GetHostForWidget(
       GetAcceleratedWidget());
@@ -1567,7 +1567,7 @@ bool NativeWindowViews::CanMaximize() const {
 bool NativeWindowViews::CanMinimize() const {
 #if BUILDFLAG(IS_WIN)
   return minimizable_;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #endif
 }
@@ -1641,7 +1641,7 @@ void NativeWindowViews::HandleKeyboardEvent(
   if (widget_destroyed_)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event.windows_key_code == ui::VKEY_BROWSER_BACK)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event.windows_key_code == ui::VKEY_BROWSER_FORWARD)
@@ -1660,7 +1660,7 @@ void NativeWindowViews::OnMouseEvent(ui::MouseEvent* e
   // Alt+Click should not toggle menu bar.
   root_view_->ResetAltState();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event->changed_button_flags() == ui::EF_BACK_MOUSE_BUTTON)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event->changed_button_flags() == ui::EF_FORWARD_MOUSE_BUTTON)
