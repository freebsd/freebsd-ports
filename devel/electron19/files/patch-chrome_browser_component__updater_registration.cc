--- chrome/browser/component_updater/registration.cc.orig	2022-05-25 04:00:47 UTC
+++ chrome/browser/component_updater/registration.cc
@@ -90,7 +90,7 @@
 #include "chrome/browser/component_updater/widevine_cdm_component_installer.h"
 #endif  // BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/component_updater/screen_ai_component_installer.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -214,7 +214,7 @@ void RegisterComponentsForUpdate() {
 
   RegisterClientSidePhishingComponent(cus);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterScreenAIComponent(cus, g_browser_process->local_state());
 #endif  // BUILDFLAG(IS_LINUX)
 
