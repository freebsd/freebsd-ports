--- electron/shell/browser/native_window_views.cc.orig	2020-12-11 21:16:23 UTC
+++ electron/shell/browser/native_window_views.cc
@@ -303,7 +303,7 @@ NativeWindowViews::NativeWindowViews(const gin_helper:
     last_window_state_ = ui::SHOW_STATE_NORMAL;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Listen to move events.
   aura::Window* window = GetNativeWindow();
   if (window)
@@ -319,7 +319,7 @@ NativeWindowViews::~NativeWindowViews() {
   SetForwardMouseMessages(false);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   aura::Window* window = GetNativeWindow();
   if (window)
     window->RemovePreTargetHandler(this);
@@ -713,7 +713,7 @@ bool NativeWindowViews::IsResizable() {
 void NativeWindowViews::SetAspectRatio(double aspect_ratio,
                                        const gfx::Size& extra_size) {
   NativeWindow::SetAspectRatio(aspect_ratio, extra_size);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   gfx::SizeF aspect(aspect_ratio, 1.0);
   // Scale up because SetAspectRatio() truncates aspect value to int
   aspect.Scale(100);
@@ -1341,7 +1341,7 @@ void NativeWindowViews::OnWidgetBoundsChanged(views::W
 }
 
 void NativeWindowViews::OnWidgetDestroying(views::Widget* widget) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   aura::Window* window = GetNativeWindow();
   if (window)
     window->RemovePreTargetHandler(this);
@@ -1434,7 +1434,7 @@ void NativeWindowViews::OnWidgetMove() {
 void NativeWindowViews::HandleKeyboardEvent(
     content::WebContents*,
     const content::NativeWebKeyboardEvent& event) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (event.windows_key_code == ui::VKEY_BROWSER_BACK)
     NotifyWindowExecuteAppCommand(kBrowserBackward);
   else if (event.windows_key_code == ui::VKEY_BROWSER_FORWARD)
@@ -1446,7 +1446,7 @@ void NativeWindowViews::HandleKeyboardEvent(
   root_view_->HandleKeyEvent(event);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void NativeWindowViews::OnMouseEvent(ui::MouseEvent* event) {
   if (event->type() != ui::ET_MOUSE_PRESSED)
     return;
