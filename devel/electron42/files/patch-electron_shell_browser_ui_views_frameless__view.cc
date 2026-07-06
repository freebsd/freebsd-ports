--- electron/shell/browser/ui/views/frameless_view.cc.orig	2026-06-03 19:18:10 UTC
+++ electron/shell/browser/ui/views/frameless_view.cc
@@ -118,7 +118,7 @@ gfx::Size FramelessView::GetMaximumSize() const {
   return window_->GetMaximumSize();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 LinuxFrameLayout* FramelessView::GetLinuxFrameLayout() const {
   return nullptr;
 }
