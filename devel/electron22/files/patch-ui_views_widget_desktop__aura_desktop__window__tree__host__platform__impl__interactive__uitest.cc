--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform_impl_interactive_uitest.cc.orig	2022-08-31 12:19:35 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform_impl_interactive_uitest.cc
@@ -22,7 +22,7 @@
 #include "ui/views/widget/widget_delegate.h"
 #include "ui/views/window/native_frame_view.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #include "ui/views/widget/desktop_aura/window_event_filter_linux.h"
 using DesktopWindowTreeHostPlatformImpl = views::DesktopWindowTreeHostLinux;
