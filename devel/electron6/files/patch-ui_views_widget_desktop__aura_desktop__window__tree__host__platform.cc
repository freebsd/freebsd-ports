--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2019-09-10 11:14:40 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -102,7 +102,7 @@ void DesktopWindowTreeHostPlatform::OnNativeWidgetCrea
     const Widget::InitParams& params) {
   native_widget_delegate_->OnNativeWidgetCreated();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Setup a non_client_window_event_filter, which handles resize/move, double
   // click and other events.
   DCHECK(!non_client_window_event_filter_);
@@ -552,7 +552,7 @@ void DesktopWindowTreeHostPlatform::Relayout() {
 }
 
 void DesktopWindowTreeHostPlatform::RemoveNonClientEventFilter() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!non_client_window_event_filter_)
     return;
 
