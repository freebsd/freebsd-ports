--- chrome/browser/ui/webui/app_settings/web_app_settings_ui.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/webui/app_settings/web_app_settings_ui.h
@@ -14,13 +14,13 @@
 #include "ui/webui/mojo_web_ui_controller.h"
 #include "ui/webui/resources/cr_components/app_management/app_management.mojom-forward.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/webui_url_constants.h"
 #include "content/public/browser/webui_config.h"
 #include "content/public/common/url_constants.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class WebAppSettingsUI;
 
 class WebAppSettingsUIConfig
