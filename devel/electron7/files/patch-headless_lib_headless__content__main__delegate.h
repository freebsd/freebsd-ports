--- headless/lib/headless_content_main_delegate.h.orig	2019-12-12 12:39:44 UTC
+++ headless/lib/headless_content_main_delegate.h
@@ -58,7 +58,7 @@ class HEADLESS_EXPORT HeadlessContentMainDelegate
 
   HeadlessBrowserImpl* browser() const { return browser_.get(); }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void ZygoteForked() override;
 #endif
 
