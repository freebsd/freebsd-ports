--- chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc
@@ -151,7 +151,7 @@ AnalysisServiceSettings::AnalysisServiceSettings(
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
