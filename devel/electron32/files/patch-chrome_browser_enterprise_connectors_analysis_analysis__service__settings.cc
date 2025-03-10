--- chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc
@@ -151,7 +151,7 @@ AnalysisServiceSettings::AnalysisServiceSettings(
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
