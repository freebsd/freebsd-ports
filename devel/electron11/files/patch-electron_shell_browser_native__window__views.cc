--- electron/shell/browser/native_window_views.cc.orig	2021-04-27 14:58:49 UTC
+++ electron/shell/browser/native_window_views.cc
@@ -306,7 +306,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
     last_window_state_ = ui::SHOW_STATE_NORMAL;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Listen to move events.
   aura::Window* window = GetNativeWindow();
   if (window)
@@ -326,7 +326,7 @@ NativeWindowViews::~NativeWindowViews() {
   SetForwardMouseMessages(false);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   aura::Window* window = GetNativeWindow();
   if (window)
     window->RemovePreTargetHandler(this);
@@ -1391,7 +1391,7 @@ void NativeWindowViews::OnWidgetBoundsChanged(views::W
 }
 
 void NativeWindowViews::OnWidgetDestroying(views::Widget* widget) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   aura::Window* window = GetNativeWindow();
   if (window)
     window->RemovePreTargetHandler(this);
@@ -1501,7 +1501,7 @@ void NativeWindowViews::HandleKeyboardEvent(
   if (widget_destroyed_)
     return;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (event.windows_key_code == ui::VKEY_BROWSER_BACK)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event.windows_key_code == ui::VKEY_BROWSER_FORWARD)
@@ -1513,7 +1513,7 @@ void NativeWindowViews::HandleKeyboardEvent(
   root_view_->HandleKeyEvent(event);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void NativeWindowViews::OnMouseEvent(ui::MouseEvent* event) {
   if (event->type() != ui::ET_MOUSE_PRESSED)
     return;
