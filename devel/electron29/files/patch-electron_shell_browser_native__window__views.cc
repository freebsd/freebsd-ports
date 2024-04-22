--- electron/shell/browser/native_window_views.cc.orig	2024-02-21 16:26:48 UTC
+++ electron/shell/browser/native_window_views.cc
@@ -51,7 +51,7 @@
 #include "ui/wm/core/shadow_types.h"
 #include "ui/wm/core/window_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_util.h"
 #include "shell/browser/browser.h"
 #include "shell/browser/linux/unity_service.h"
@@ -293,7 +293,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
     params.parent = parent->GetNativeWindow();
 
   params.native_widget = new ElectronDesktopNativeWidgetAura(this);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string name = Browser::Get()->GetName();
   // Set WM_WINDOW_ROLE.
   params.wm_role_name = "browser-window";
@@ -318,7 +318,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
   std::string window_type;
   options.Get(options::kType, &window_type);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set _GTK_THEME_VARIANT to dark if we have "dark-theme" option set.
   bool use_dark_theme = false;
   if (options.Get(options::kDarkTheme, &use_dark_theme) && use_dark_theme) {
@@ -420,7 +420,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
   if (window)
     window->AddPreTargetHandler(this);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On linux after the widget is initialized we might have to force set the
   // bounds if the bounds are smaller than the current display
   SetBounds(gfx::Rect(GetPosition(), bounds.size()), false);
@@ -456,7 +456,7 @@ void NativeWindowViews::SetGTKDarkThemeEnabled(bool us
 }
 
 void NativeWindowViews::SetGTKDarkThemeEnabled(bool use_dark_theme) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsX11()) {
     const std::string color = use_dark_theme ? "dark" : "light";
     auto* connection = x11::Connection::Get();
@@ -518,7 +518,7 @@ void NativeWindowViews::Show() {
 
   NotifyWindowShow();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (global_menu_bar_)
     global_menu_bar_->OnWindowMapped();
 
@@ -534,7 +534,7 @@ void NativeWindowViews::ShowInactive() {
 
   NotifyWindowShow();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (global_menu_bar_)
     global_menu_bar_->OnWindowMapped();
 #endif
@@ -548,7 +548,7 @@ void NativeWindowViews::Hide() {
 
   NotifyWindowHide();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (global_menu_bar_)
     global_menu_bar_->OnWindowUnmapped();
 #endif
@@ -579,7 +579,7 @@ bool NativeWindowViews::IsEnabled() const {
 bool NativeWindowViews::IsEnabled() const {
 #if BUILDFLAG(IS_WIN)
   return ::IsWindowEnabled(GetAcceleratedWidget());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsX11())
     return !event_disabler_.get();
   NOTIMPLEMENTED();
@@ -635,7 +635,7 @@ void NativeWindowViews::SetEnabledInternal(bool enable
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NativeWindowViews::Maximize() {
   if (IsVisible()) {
     widget()->Maximize();
@@ -775,7 +775,7 @@ void NativeWindowViews::SetBounds(const gfx::Rect& bou
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux and Windows the minimum and maximum size should be updated with
   // window size when window is not resizable.
   if (!resizable_) {
@@ -1035,7 +1035,7 @@ bool NativeWindowViews::IsClosable() const {
     return false;
   }
   return !(info.fState & MFS_DISABLED);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #endif
 }
@@ -1283,7 +1283,7 @@ void NativeWindowViews::SetMenu(ElectronMenuModel* men
 }
 
 void NativeWindowViews::SetMenu(ElectronMenuModel* menu_model) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Remove global menu bar.
   if (global_menu_bar_ && menu_model == nullptr) {
     global_menu_bar_.reset();
@@ -1382,7 +1382,7 @@ void NativeWindowViews::SetParentWindow(NativeWindow* 
 void NativeWindowViews::SetParentWindow(NativeWindow* parent) {
   NativeWindow::SetParentWindow(parent);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsX11()) {
     auto* connection = x11::Connection::Get();
     connection->SetProperty(
@@ -1428,7 +1428,7 @@ void NativeWindowViews::SetProgressBar(double progress
                                        NativeWindow::ProgressState state) {
 #if BUILDFLAG(IS_WIN)
   taskbar_host_.SetProgressBar(GetAcceleratedWidget(), progress, state);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (unity::IsRunning()) {
     unity::SetProgressFraction(progress);
   }
@@ -1499,7 +1499,7 @@ bool NativeWindowViews::IsVisibleOnAllWorkspaces() con
 }
 
 bool NativeWindowViews::IsVisibleOnAllWorkspaces() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsX11()) {
     // Use the presence/absence of _NET_WM_STATE_STICKY in _NET_WM_STATE to
     // determine whether the current window is visible on all workspaces.
@@ -1522,7 +1522,7 @@ content::DesktopMediaID NativeWindowViews::GetDesktopM
 #if BUILDFLAG(IS_WIN)
   window_handle =
       reinterpret_cast<content::DesktopMediaID::Id>(accelerated_widget);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   window_handle = static_cast<uint32_t>(accelerated_widget);
 #endif
   aura::WindowTreeHost* const host =
@@ -1620,7 +1620,7 @@ void NativeWindowViews::SetIcon(HICON window_icon, HIC
   SendMessage(hwnd, WM_SETICON, ICON_BIG,
               reinterpret_cast<LPARAM>(app_icon_.get()));
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NativeWindowViews::SetIcon(const gfx::ImageSkia& icon) {
   auto* tree_host = views::DesktopWindowTreeHostLinux::GetHostForWidget(
       GetAcceleratedWidget());
@@ -1706,7 +1706,7 @@ bool NativeWindowViews::CanMinimize() const {
 bool NativeWindowViews::CanMinimize() const {
 #if BUILDFLAG(IS_WIN)
   return minimizable_;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #endif
 }
@@ -1758,7 +1758,7 @@ void NativeWindowViews::HandleKeyboardEvent(
   if (widget_destroyed_)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event.windows_key_code == ui::VKEY_BROWSER_BACK)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event.windows_key_code == ui::VKEY_BROWSER_FORWARD)
@@ -1777,7 +1777,7 @@ void NativeWindowViews::OnMouseEvent(ui::MouseEvent* e
   // Alt+Click should not toggle menu bar.
   root_view_.ResetAltState();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event->changed_button_flags() == ui::EF_BACK_MOUSE_BUTTON)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event->changed_button_flags() == ui::EF_FORWARD_MOUSE_BUTTON)
