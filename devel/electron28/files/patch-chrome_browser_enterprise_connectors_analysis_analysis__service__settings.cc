--- chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc.orig	2023-10-19 19:58:04 UTC
+++ chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc
@@ -143,7 +143,7 @@ AnalysisServiceSettings::AnalysisServiceSettings(
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
