--- content/browser/webui/web_ui_main_frame_observer.cc.orig	2025-03-24 20:50:14 UTC
+++ content/browser/webui/web_ui_main_frame_observer.cc
@@ -47,7 +47,7 @@ bool IsWebUIJavaScriptErrorReportingSupported() {
 bool IsWebUIJavaScriptErrorReportingSupported() {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return false;
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return base::FeatureList::IsEnabled(features::kWebUIJSErrorReportingExtended);
