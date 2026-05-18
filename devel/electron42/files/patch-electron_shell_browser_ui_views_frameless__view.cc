--- electron/shell/browser/ui/views/frameless_view.cc.orig	2026-03-17 08:46:52 UTC
+++ electron/shell/browser/ui/views/frameless_view.cc
@@ -123,7 +123,7 @@ gfx::Size FramelessView::GetMaximumSize() const {
   return window_->GetMaximumSize();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 LinuxFrameLayout* FramelessView::GetLinuxFrameLayout() const {
   return nullptr;
 }
