--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.h.orig	2019-12-16 13:32:59 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.h
@@ -146,7 +146,7 @@ class VIEWS_EXPORT DesktopWindowTreeHostPlatform
   DesktopWindowTreeHostPlatform* window_parent_ = nullptr;
   std::set<DesktopWindowTreeHostPlatform*> window_children_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // A handler for events intended for non client area.
   std::unique_ptr<WindowEventFilter> non_client_window_event_filter_;
 #endif
