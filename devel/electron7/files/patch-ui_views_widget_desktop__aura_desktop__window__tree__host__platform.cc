--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2019-12-16 13:32:59 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -143,7 +143,7 @@ void DesktopWindowTreeHostPlatform::OnNativeWidgetCrea
                                            Widget::InitParams::TYPE_WINDOW &&
                                        !params.remove_standard_frame);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Setup a non_client_window_event_filter, which handles resize/move, double
   // click and other events.
   DCHECK(!non_client_window_event_filter_);
@@ -699,7 +699,7 @@ void DesktopWindowTreeHostPlatform::Relayout() {
 }
 
 void DesktopWindowTreeHostPlatform::RemoveNonClientEventFilter() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!non_client_window_event_filter_)
     return;
 
