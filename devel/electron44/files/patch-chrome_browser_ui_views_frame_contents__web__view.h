--- chrome/browser/ui/views/frame/contents_web_view.h.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/ui/views/frame/contents_web_view.h
@@ -68,7 +68,7 @@ class ContentsWebView : public views::WebView,
   // This allows the browser to force focus synchronization in split view even
   // when native OS focus gets stuck on a different window (like a permission
   // prompt).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void DidGetUserInteraction(const blink::WebInputEvent& event) override;
 #endif
 
