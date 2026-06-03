--- chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc.orig	2025-10-21 20:19:54 UTC
+++ chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc
@@ -192,7 +192,7 @@ void AnalysisServiceSettings::ParseVerificationSignatu
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
