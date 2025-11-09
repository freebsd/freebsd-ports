--- chrome/browser/ui/webui/connectors_internals/connectors_internals_page_handler.cc.orig	2025-10-21 20:19:54 UTC
+++ chrome/browser/ui/webui/connectors_internals/connectors_internals_page_handler.cc
@@ -85,7 +85,7 @@ connectors_internals::mojom::ClientIdentityPtr GetIden
 #endif  // BUILDFLAG(ENTERPRISE_CLIENT_CERTIFICATES)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 std::string GetStringFromTimestamp(base::Time timestamp) {
   return (timestamp == base::Time()) ? std::string()
                                      : base::UnlocalizedTimeFormatWithPattern(
@@ -200,7 +200,7 @@ void ConnectorsInternalsPageHandler::GetSignalsReporti
 void ConnectorsInternalsPageHandler::GetSignalsReportingState(
     GetSignalsReportingStateCallback callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   auto* profile_prefs = profile_->GetPrefs();
 
   std::string last_upload_attempt_time_string =
