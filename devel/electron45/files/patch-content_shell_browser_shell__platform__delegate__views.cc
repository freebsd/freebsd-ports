--- content/shell/browser/shell_platform_delegate_views.cc.orig	2026-04-28 21:06:17 UTC
+++ content/shell/browser/shell_platform_delegate_views.cc
@@ -374,7 +374,7 @@ void ShellPlatformDelegate::CreatePlatformWindow(
       views::Widget::InitParams::NATIVE_WIDGET_OWNS_WIDGET);
   params.bounds = gfx::Rect(initial_size);
   params.delegate = delegate.release();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.wm_class_class = "chromium-content_shell";
   params.wm_class_name = params.wm_class_class;
 #endif  // BUILDFLAG(IS_LINUX)
