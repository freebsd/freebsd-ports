--- content/browser/webui/web_ui_main_frame_observer.cc.orig	2026-04-28 21:06:17 UTC
+++ content/browser/webui/web_ui_main_frame_observer.cc
@@ -51,7 +51,7 @@ bool IsWebUIJavaScriptErrorReportingSupported() {
 bool IsWebUIJavaScriptErrorReportingSupported() {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return false;
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return base::FeatureList::IsEnabled(features::kWebUIJSErrorReportingExtended);
