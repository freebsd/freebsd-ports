--- chrome/browser/chrome_browser_interface_binders_webui.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/chrome_browser_interface_binders_webui.cc
@@ -48,20 +48,20 @@
 #include "content/public/browser/web_ui_controller_interface_binder.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/connectors_internals/connectors_internals.mojom.h"
 #include "chrome/browser/ui/webui/connectors_internals/connectors_internals_ui.h"
 #include "ui/webui/resources/cr_components/app_management/app_management.mojom.h"
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #include "chrome/browser/ui/webui/discards/site_data.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/app_settings/web_app_settings_ui.h"
 #include "chrome/browser/ui/webui/on_device_translation_internals/on_device_translation_internals_ui.h"
 #include "chrome/browser/ui/webui/signin/history_sync_optin/history_sync_optin.mojom.h"
@@ -460,7 +460,7 @@ void PopulateChromeWebUIFrameBinders(
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<
       connectors_internals::mojom::PageHandler,
       enterprise_connectors::ConnectorsInternalsUI>(map);
@@ -471,7 +471,7 @@ void PopulateChromeWebUIFrameBinders(
                                          policy::DlpInternalsUI>(map);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<
       app_management::mojom::PageHandlerFactory, WebAppSettingsUI>(map);
 
@@ -609,14 +609,14 @@ void PopulateChromeWebUIFrameBinders(
         HistoryClustersSidePanelUI, NewTabPageUI, BookmarksSidePanelUI>(map);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<whats_new::mojom::PageHandlerFactory,
                                          WhatsNewUI>(map);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
   RegisterWebUIControllerInterfaceBinder<
       browser_command::mojom::CommandHandlerFactory,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       WhatsNewUI,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
       NewTabPageUI>(map);
@@ -1154,7 +1154,7 @@ void PopulateChromeWebUIFrameBinders(
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<discards::mojom::DetailsProvider,
                                          DiscardsUI>(map);
 
