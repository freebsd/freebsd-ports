--- weblayer/browser/system_network_context_manager.cc.orig	2022-03-25 21:59:56 UTC
+++ weblayer/browser/system_network_context_manager.cc
@@ -69,7 +69,7 @@ void SystemNetworkContextManager::ConfigureDefaultNetw
   network_context_params->user_agent = user_agent;
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // We're not configuring the cookie encryption on these platforms yet.
   network_context_params->enable_encrypted_cookies = false;
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) ||
