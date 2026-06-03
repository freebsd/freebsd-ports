--- electron/shell/browser/ui/views/frameless_view.cc.orig	2026-05-14 05:52:47 UTC
+++ electron/shell/browser/ui/views/frameless_view.cc
@@ -122,7 +122,7 @@ gfx::Size FramelessView::GetMaximumSize() const {
   return window_->GetMaximumSize();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 LinuxFrameLayout* FramelessView::GetLinuxFrameLayout() const {
   return nullptr;
 }
