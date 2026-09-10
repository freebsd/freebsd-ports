--- components/regional_capabilities/regional_capabilities_service.cc.orig	2026-06-23 23:37:18 UTC
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -420,7 +420,7 @@ bool RegionalCapabilitiesService::IsInAnySearchEngineC
       .choice_screen_eligibility_config.has_value();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 bool RegionalCapabilitiesService::IsInAnySearchEngineChoiceScreenRegion(
     Client& client) {
