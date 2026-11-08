--- chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc.orig	2026-08-24 20:59:34 UTC
+++ chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc
@@ -254,7 +254,7 @@ bool BrowserViewTabbedLayoutImpl::AvoidCrackingForFrac
 }
 
 bool BrowserViewTabbedLayoutImpl::AvoidCrackingForFractionalDisplay() const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // This is primarily an issue on Linux and Windows; add other platforms here
   // as needed.
   if (auto* const widget = views().browser_view->GetWidget()) {
