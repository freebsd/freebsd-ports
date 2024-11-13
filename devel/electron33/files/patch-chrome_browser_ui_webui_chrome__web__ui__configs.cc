--- chrome/browser/ui/webui/chrome_web_ui_configs.cc.orig	2024-10-16 21:31:03 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_configs.cc
@@ -77,7 +77,7 @@
 #include "chrome/browser/ui/webui/certificate_manager/certificate_manager_ui.h"
 #endif  // BUILDFLAG(CHROME_ROOT_STORE_CERT_MANAGEMENT_UI)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_ui.h"
 #endif
 
@@ -148,10 +148,10 @@ void RegisterChromeWebUIConfigs() {
   map.AddWebUIConfig(std::make_unique<WebuiGalleryUIConfig>());
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   map.AddWebUIConfig(std::make_unique<LinuxProxyConfigUI>());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_OPENBSD)
+        // BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(ENABLE_EXTENSIONS)
   map.AddWebUIConfig(std::make_unique<extensions::ExtensionsUIConfig>());
@@ -165,7 +165,7 @@ void RegisterChromeWebUIConfigs() {
   map.AddWebUIConfig(std::make_unique<CertificateManagerUIConfig>());
 #endif  // BUILDFLAG(CHROME_ROOT_STORE_CERT_MANAGEMENT_UI)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   map.AddWebUIConfig(std::make_unique<WhatsNewUIConfig>());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
