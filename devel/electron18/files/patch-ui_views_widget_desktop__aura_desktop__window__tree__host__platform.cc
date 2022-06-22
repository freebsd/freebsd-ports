--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2022-05-19 05:18:02 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -915,7 +915,7 @@ display::Display DesktopWindowTreeHostPlatform::GetDis
 // DesktopWindowTreeHost:
 
 // Linux subclasses this host and adds some Linux specific bits.
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 // static
 DesktopWindowTreeHost* DesktopWindowTreeHost::Create(
     internal::NativeWidgetDelegate* native_widget_delegate,
