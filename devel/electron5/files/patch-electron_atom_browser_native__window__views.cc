--- electron/atom/browser/native_window_views.cc.orig	2019-08-19 21:30:51 UTC
+++ electron/atom/browser/native_window_views.cc
@@ -290,7 +290,7 @@ NativeWindowViews::NativeWindowViews(const mate::Dicti
   last_normal_bounds_ = GetBounds();
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Listen to move events.
   aura::Window* window = GetNativeWindow();
   if (window)
@@ -306,7 +306,7 @@ NativeWindowViews::~NativeWindowViews() {
   SetForwardMouseMessages(false);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   aura::Window* window = GetNativeWindow();
   if (window)
     window->RemovePreTargetHandler(this);
@@ -1228,7 +1228,7 @@ void NativeWindowViews::OnWidgetBoundsChanged(views::W
 }
 
 void NativeWindowViews::OnWidgetDestroying(views::Widget* widget) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   aura::Window* window = GetNativeWindow();
   if (window)
     window->RemovePreTargetHandler(this);
@@ -1321,7 +1321,7 @@ void NativeWindowViews::OnWidgetMove() {
 void NativeWindowViews::HandleKeyboardEvent(
     content::WebContents*,
     const content::NativeWebKeyboardEvent& event) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (event.windows_key_code == ui::VKEY_BROWSER_BACK)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event.windows_key_code == ui::VKEY_BROWSER_FORWARD)
@@ -1333,7 +1333,7 @@ void NativeWindowViews::HandleKeyboardEvent(
   root_view_->HandleKeyEvent(event);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void NativeWindowViews::OnMouseEvent(ui::MouseEvent* event) {
   if (event->type() != ui::ET_MOUSE_PRESSED)
     return;
