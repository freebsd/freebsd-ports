--- electron/shell/browser/native_window_views.cc.orig	2026-09-29 23:27:57 UTC
+++ electron/shell/browser/native_window_views.cc
@@ -58,7 +58,7 @@
 #include "ui/views/window/non_client_view.h"
 #include "ui/wm/core/window_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/notimplemented.h"
 #include "shell/browser/browser.h"
 #include "shell/browser/linux/launcher_entry.h"
@@ -298,7 +298,7 @@ NativeWindowViews::NativeWindowViews(const int32_t bas
   // If a client frame, we need to draw our own shadows.
   if (transparent() || has_client_frame())
     params.opacity = InitParams::WindowOpacity::kTranslucent;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Resize handles and shadows on frameless windows need translucent insets.
   if (!has_frame())
     params.opacity = InitParams::WindowOpacity::kTranslucent;
@@ -317,7 +317,7 @@ NativeWindowViews::NativeWindowViews(const int32_t bas
     params.parent = parent->GetNativeWindow();
 
   params.native_widget = new ElectronDesktopNativeWidgetAura{this, widget()};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the WM_CLASS and XDG App ID to the same value
   // for best compatibility with both X11 and Wayland.
   const auto app_id = platform_util::GetXdgAppId();
@@ -347,7 +347,7 @@ NativeWindowViews::NativeWindowViews(const int32_t bas
   std::string window_type;
   options.Get(options::kType, &window_type);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set _GTK_THEME_VARIANT to dark if we have "dark-theme" option set.
   if (options.ValueOrDefault(options::kDarkTheme, false))
     SetGTKDarkThemeEnabled(true);
@@ -423,7 +423,7 @@ NativeWindowViews::NativeWindowViews(const int32_t bas
   ::SetWindowLong(GetAcceleratedWidget(), GWL_EXSTYLE, ex_style);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   options.Get(options::kRoundedCorners, &rounded_corner_);
 #endif
 
@@ -543,7 +543,7 @@ void NativeWindowViews::SetTitleBarOverlay(
     auto* fv = widget()->non_client_view()->frame_view();
     if (auto* frameless = views::AsViewClass<FramelessView>(fv)) {
       frameless->InvalidateCaptionButtons();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     } else if (auto* fvl = views::AsViewClass<views::FrameViewLinux>(fv)) {
       fvl->InvalidateLayout();
       fvl->SchedulePaint();
@@ -553,7 +553,7 @@ void NativeWindowViews::SetGTKDarkThemeEnabled(bool us
 }
 
 void NativeWindowViews::SetGTKDarkThemeEnabled(bool use_dark_theme) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (x11_util::IsX11()) {
     const std::string color = use_dark_theme ? "dark" : "light";
     auto* connection = x11::Connection::Get();
@@ -621,7 +621,7 @@ void NativeWindowViews::Show() {
 
   NotifyWindowShow();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (global_menu_bar_)
     global_menu_bar_->OnWindowMapped();
 
@@ -639,7 +639,7 @@ void NativeWindowViews::ShowInactive() {
 
   NotifyWindowShow();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (global_menu_bar_)
     global_menu_bar_->OnWindowMapped();
 
@@ -658,7 +658,7 @@ void NativeWindowViews::Hide() {
 
   NotifyWindowHide();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (global_menu_bar_)
     global_menu_bar_->OnWindowUnmapped();
 #endif
@@ -689,7 +689,7 @@ bool NativeWindowViews::IsEnabled() const {
 bool NativeWindowViews::IsEnabled() const {
 #if BUILDFLAG(IS_WIN)
   return ::IsWindowEnabled(GetAcceleratedWidget());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return !enable_event_listening_;
 #endif
 }
@@ -906,7 +906,7 @@ void NativeWindowViews::SetBounds(const gfx::Rect& bou
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux and Windows the minimum and maximum size should be updated with
   // window size when window is not resizable.
   if (!CanResize()) {
@@ -961,7 +961,7 @@ void NativeWindowViews::SetContentSizeConstraints(
   // of this to determine whether native widget has initialized.
   if (widget() && widget()->widget_delegate())
     widget()->OnSizeConstraintsChanged();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (resizable_)
     old_size_constraints_ = GetSizeConstraints();
 #endif
@@ -1181,7 +1181,7 @@ bool NativeWindowViews::IsClosable() const {
     return false;
   }
   return !(info.fState & MFS_DISABLED);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #endif
 }
@@ -1321,7 +1321,7 @@ void NativeWindowViews::SetBackgroundColor(SkColor bac
   InvalidateRect(GetAcceleratedWidget(), nullptr, 1);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Widget and root view need to be transparent for CSD to draw shadow regions
   // and custom edges and corners. The web contents view will still be
   // painted with the true background color, which is cached in state.
@@ -1344,7 +1344,7 @@ void NativeWindowViews::SetHasShadow(bool has_shadow) 
   // so we no longer call wm::SetShadowElevation and similar to avoid
   // artifacts. https://github.com/electron/electron/issues/51456.
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* efvl = views::AsViewClass<ElectronFrameViewLinux>(
       widget()->non_client_view()->frame_view());
   if (efvl) {
@@ -1378,7 +1378,7 @@ void NativeWindowViews::SetOpacity(const double opacit
   HWND hwnd = GetAcceleratedWidget();
   SetLayered();
   ::SetLayeredWindowAttributes(hwnd, 0, bounded_opacity * 255, LWA_ALPHA);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   widget()->SetOpacity(static_cast<float>(bounded_opacity));
 #endif
 }
@@ -1469,7 +1469,7 @@ void NativeWindowViews::SetMenu(ElectronMenuModel* men
 }
 
 void NativeWindowViews::SetMenu(ElectronMenuModel* menu_model) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Remove global menu bar.
   bool try_global_menu_bar = true;
   if (global_menu_bar_ && menu_model == nullptr) {
@@ -1537,7 +1537,7 @@ void NativeWindowViews::SetParentWindow(NativeWindow* 
 void NativeWindowViews::SetParentWindow(NativeWindow* parent) {
   NativeWindow::SetParentWindow(parent);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (x11_util::IsX11()) {
     auto* connection = x11::Connection::Get();
     connection->SetProperty(
@@ -1591,7 +1591,7 @@ gfx::Insets NativeWindowViews::GetRestoredFrameBorderI
   if (auto* frameless = views::AsViewClass<FramelessView>(frame_view))
     return frameless->RestoredFrameBorderInsets();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* fvl = views::AsViewClass<views::FrameViewLinux>(frame_view))
     return fvl->GetRestoredFrameBorderInsets();
 #endif
@@ -1603,7 +1603,7 @@ void NativeWindowViews::SetProgressBar(double progress
                                        NativeWindow::ProgressState state) {
 #if BUILDFLAG(IS_WIN)
   taskbar_host_.SetProgressBar(GetAcceleratedWidget(), progress, state);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   launcher_entry::SetProgress(progress);
 #endif
 }
@@ -1727,7 +1727,7 @@ content::DesktopMediaID NativeWindowViews::GetDesktopM
 #if BUILDFLAG(IS_WIN)
   window_handle =
       reinterpret_cast<content::DesktopMediaID::Id>(accelerated_widget);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   window_handle = static_cast<uint32_t>(accelerated_widget);
 #endif
   aura::WindowTreeHost* const host =
@@ -1857,7 +1857,7 @@ void NativeWindowViews::SetIcon(HICON window_icon, HIC
   SendMessage(hwnd, WM_SETICON, ICON_BIG,
               reinterpret_cast<LPARAM>(app_icon_.get()));
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NativeWindowViews::SetIcon(const gfx::ImageSkia& icon) {
   auto* tree_host = views::DesktopWindowTreeHostLinux::GetHostForWidget(
       GetAcceleratedWidget());
@@ -1978,7 +1978,7 @@ bool NativeWindowViews::CanMinimize() const {
 bool NativeWindowViews::CanMinimize() const {
 #if BUILDFLAG(IS_WIN)
   return minimizable_;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #endif
 }
@@ -2045,7 +2045,7 @@ std::unique_ptr<views::FrameView> NativeWindowViews::C
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 views::FrameViewLinux* NativeWindowViews::GetFrameViewLinux() const {
   auto* ncv = widget()->non_client_view();
   if (!ncv)
@@ -2064,7 +2064,7 @@ void NativeWindowViews::HandleKeyboardEvent(
   if (widget_destroyed_)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event.windows_key_code == ui::VKEY_BROWSER_BACK)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event.windows_key_code == ui::VKEY_BROWSER_FORWARD)
@@ -2083,7 +2083,7 @@ void NativeWindowViews::OnMouseEvent(ui::MouseEvent* e
   // Alt+Click should not toggle menu bar.
   root_view_.ResetAltState();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event->changed_button_flags() == ui::EF_BACK_MOUSE_BUTTON)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event->changed_button_flags() == ui::EF_FORWARD_MOUSE_BUTTON)
