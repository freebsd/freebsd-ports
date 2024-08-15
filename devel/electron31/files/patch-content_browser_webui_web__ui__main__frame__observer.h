--- content/browser/webui/web_ui_main_frame_observer.h.orig	2024-06-18 21:43:32 UTC
+++ content/browser/webui/web_ui_main_frame_observer.h
@@ -44,7 +44,7 @@ class CONTENT_EXPORT WebUIMainFrameObserver : public W
 
 // TODO(crbug.com/40149439) This is currently disabled due to Windows DLL
 // thunking issues. Fix & re-enable.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On official Google builds, capture and report JavaScript error messages on
   // WebUI surfaces back to Google. This allows us to fix JavaScript errors and
   // exceptions.
@@ -60,7 +60,7 @@ class CONTENT_EXPORT WebUIMainFrameObserver : public W
   void ReadyToCommitNavigation(NavigationHandle* navigation_handle) override;
 
  private:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void MaybeEnableWebUIJavaScriptErrorReporting(
       NavigationHandle* navigation_handle);
 
