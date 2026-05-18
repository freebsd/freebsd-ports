--- electron/shell/browser/native_window_views.cc.orig	2026-05-08 13:54:01 UTC
+++ electron/shell/browser/native_window_views.cc
@@ -58,7 +58,7 @@
 #include "ui/wm/core/shadow_types.h"
 #include "ui/wm/core/window_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/notimplemented.h"
 #include "shell/browser/browser.h"
 #include "shell/browser/linux/unity_service.h"
@@ -292,7 +292,7 @@ NativeWindowViews::NativeWindowViews(const int32_t bas
     params.parent = parent->GetNativeWindow();
 
   params.native_widget = new ElectronDesktopNativeWidgetAura{this, widget()};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the WM_CLASS and XDG App ID to the same value
   // for best compatibility with both X11 and Wayland.
   const auto app_id = platform_util::GetXdgAppId();
@@ -322,7 +322,7 @@ NativeWindowViews::NativeWindowViews(const int32_t bas
   std::string window_type;
   options.Get(options::kType, &window_type);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set _GTK_THEME_VARIANT to dark if we have "dark-theme" option set.
   if (options.ValueOrDefault(options::kDarkTheme, false))
     SetGTKDarkThemeEnabled(true);
@@ -443,7 +443,7 @@ NativeWindowViews::NativeWindowViews(const int32_t bas
   if (window)
     window->AddPreTargetHandler(this);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // The initial params.bounds was applied before the frame view existed, so
   // non-client insets weren't accounted for and bounds need to be set again.
   if (!GetRestoredFrameBorderInsets().IsEmpty())
@@ -518,7 +518,7 @@ void NativeWindowViews::SetGTKDarkThemeEnabled(bool us
 }
 
 void NativeWindowViews::SetGTKDarkThemeEnabled(bool use_dark_theme) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (x11_util::IsX11()) {
     const std::string color = use_dark_theme ? "dark" : "light";
     auto* connection = x11::Connection::Get();
@@ -579,7 +579,7 @@ void NativeWindowViews::Show() {
 
   NotifyWindowShow();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (global_menu_bar_)
     global_menu_bar_->OnWindowMapped();
 
@@ -595,7 +595,7 @@ void NativeWindowViews::ShowInactive() {
 
   NotifyWindowShow();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (global_menu_bar_)
     global_menu_bar_->OnWindowMapped();
 
@@ -614,7 +614,7 @@ void NativeWindowViews::Hide() {
 
   NotifyWindowHide();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (global_menu_bar_)
     global_menu_bar_->OnWindowUnmapped();
 #endif
@@ -645,7 +645,7 @@ bool NativeWindowViews::IsEnabled() const {
 bool NativeWindowViews::IsEnabled() const {
 #if BUILDFLAG(IS_WIN)
   return ::IsWindowEnabled(GetAcceleratedWidget());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (x11_util::IsX11())
     return !event_disabler_.get();
   NOTIMPLEMENTED();
@@ -870,7 +870,7 @@ void NativeWindowViews::SetBounds(const gfx::Rect& bou
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux and Windows the minimum and maximum size should be updated with
   // window size when window is not resizable.
   if (!CanResize()) {
@@ -925,7 +925,7 @@ void NativeWindowViews::SetContentSizeConstraints(
   // of this to determine whether native widget has initialized.
   if (widget() && widget()->widget_delegate())
     widget()->OnSizeConstraintsChanged();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (resizable_)
     old_size_constraints_ = GetSizeConstraints();
 #endif
@@ -1140,7 +1140,7 @@ bool NativeWindowViews::IsClosable() const {
     return false;
   }
   return !(info.fState & MFS_DISABLED);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #endif
 }
@@ -1180,7 +1180,7 @@ void NativeWindowViews::Center() {
 // for now to avoid breaking API contract, but should consider the long
 // term plan for this aligning with upstream.
 void NativeWindowViews::Center() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto display =
       display::Screen::Get()->GetDisplayNearestWindow(GetNativeWindow());
   gfx::Rect window_bounds_in_screen = display.work_area();
@@ -1284,7 +1284,7 @@ void NativeWindowViews::SetBackgroundColor(SkColor bac
   InvalidateRect(GetAcceleratedWidget(), nullptr, 1);
 #endif
   SkColor compositor_color = background_color;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Widget background needs to stay transparent for CSD shadow regions.
   LinuxFrameLayout* frame_layout = GetLinuxFrameLayout();
   const bool uses_csd =
@@ -1406,7 +1406,7 @@ void NativeWindowViews::SetMenu(ElectronMenuModel* men
 }
 
 void NativeWindowViews::SetMenu(ElectronMenuModel* menu_model) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Remove global menu bar.
   if (global_menu_bar_ && menu_model == nullptr) {
     global_menu_bar_.reset();
@@ -1462,7 +1462,7 @@ void NativeWindowViews::SetParentWindow(NativeWindow* 
 void NativeWindowViews::SetParentWindow(NativeWindow* parent) {
   NativeWindow::SetParentWindow(parent);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (x11_util::IsX11()) {
     auto* connection = x11::Connection::Get();
     connection->SetProperty(
@@ -1524,7 +1524,7 @@ void NativeWindowViews::SetProgressBar(double progress
                                        NativeWindow::ProgressState state) {
 #if BUILDFLAG(IS_WIN)
   taskbar_host_.SetProgressBar(GetAcceleratedWidget(), progress, state);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (unity::IsRunning()) {
     unity::SetProgressFraction(progress);
   }
@@ -1650,7 +1650,7 @@ content::DesktopMediaID NativeWindowViews::GetDesktopM
 #if BUILDFLAG(IS_WIN)
   window_handle =
       reinterpret_cast<content::DesktopMediaID::Id>(accelerated_widget);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   window_handle = static_cast<uint32_t>(accelerated_widget);
 #endif
   aura::WindowTreeHost* const host =
@@ -1780,7 +1780,7 @@ void NativeWindowViews::SetIcon(HICON window_icon, HIC
   SendMessage(hwnd, WM_SETICON, ICON_BIG,
               reinterpret_cast<LPARAM>(app_icon_.get()));
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NativeWindowViews::SetIcon(const gfx::ImageSkia& icon) {
   auto* tree_host = views::DesktopWindowTreeHostLinux::GetHostForWidget(
       GetAcceleratedWidget());
@@ -1901,7 +1901,7 @@ bool NativeWindowViews::CanMinimize() const {
 bool NativeWindowViews::CanMinimize() const {
 #if BUILDFLAG(IS_WIN)
   return minimizable_;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #endif
 }
@@ -1943,7 +1943,7 @@ std::unique_ptr<views::FrameView> NativeWindowViews::C
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 LinuxFrameLayout* NativeWindowViews::GetLinuxFrameLayout() {
   auto* ncv = widget()->non_client_view();
   if (!ncv)
@@ -1963,7 +1963,7 @@ void NativeWindowViews::HandleKeyboardEvent(
   if (widget_destroyed_)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event.windows_key_code == ui::VKEY_BROWSER_BACK)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event.windows_key_code == ui::VKEY_BROWSER_FORWARD)
@@ -1982,7 +1982,7 @@ void NativeWindowViews::OnMouseEvent(ui::MouseEvent* e
   // Alt+Click should not toggle menu bar.
   root_view_.ResetAltState();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event->changed_button_flags() == ui::EF_BACK_MOUSE_BUTTON)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event->changed_button_flags() == ui::EF_FORWARD_MOUSE_BUTTON)
