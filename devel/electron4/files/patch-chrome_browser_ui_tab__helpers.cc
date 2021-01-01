--- chrome/browser/ui/tab_helpers.cc.orig	2019-03-15 06:37:06 UTC
+++ chrome/browser/ui/tab_helpers.cc
@@ -306,7 +306,7 @@ void TabHelpers::AttachTabHelpers(WebContents* web_con
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopSessionDurationObserver::CreateForWebContents(web_contents);
 #endif
 
