--- electron/atom/browser/native_window_views.cc.orig	2020-02-21 13:27:02 UTC
+++ electron/atom/browser/native_window_views.cc
@@ -304,7 +304,7 @@ NativeWindowViews::NativeWindowViews(const mate::Dicti
     last_window_state_ = ui::SHOW_STATE_NORMAL;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Listen to move events.
   aura::Window* window = GetNativeWindow();
   if (window)
@@ -320,7 +320,7 @@ NativeWindowViews::~NativeWindowViews() {
   SetForwardMouseMessages(false);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   aura::Window* window = GetNativeWindow();
   if (window)
     window->RemovePreTargetHandler(this);
@@ -1229,7 +1229,7 @@ void NativeWindowViews::OnWidgetBoundsChanged(views::W
 }
 
 void NativeWindowViews::OnWidgetDestroying(views::Widget* widget) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   aura::Window* window = GetNativeWindow();
   if (window)
     window->RemovePreTargetHandler(this);
@@ -1322,7 +1322,7 @@ void NativeWindowViews::OnWidgetMove() {
 void NativeWindowViews::HandleKeyboardEvent(
     content::WebContents*,
     const content::NativeWebKeyboardEvent& event) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (event.windows_key_code == ui::VKEY_BROWSER_BACK)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event.windows_key_code == ui::VKEY_BROWSER_FORWARD)
@@ -1334,7 +1334,7 @@ void NativeWindowViews::HandleKeyboardEvent(
   root_view_->HandleKeyEvent(event);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void NativeWindowViews::OnMouseEvent(ui::MouseEvent* event) {
   if (event->type() != ui::ET_MOUSE_PRESSED)
     return;
