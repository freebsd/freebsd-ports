--- chrome/browser/chrome_browser_interface_binders.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/chrome_browser_interface_binders.cc
@@ -132,12 +132,12 @@
 #endif  // BUILDFLAG(FULL_SAFE_BROWSING)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/connectors_internals/connectors_internals.mojom.h"
 #include "chrome/browser/ui/webui/connectors_internals/connectors_internals_ui.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/app_settings/web_app_settings_ui.h"
 #include "ui/webui/resources/cr_components/app_management/app_management.mojom.h"
 #endif
@@ -228,7 +228,7 @@
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/companion/visual_query/visual_query_suggestions_service_factory.h"
 #include "chrome/browser/ui/web_applications/sub_apps_service_impl.h"
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
@@ -854,7 +854,7 @@ void BindScreen2xMainContentExtractor(
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 void BindVisualSuggestionsModelProvider(
     content::RenderFrameHost* frame_host,
     mojo::PendingReceiver<
@@ -1050,7 +1050,7 @@ void PopulateChromeFrameBinders(
 #endif  // BUILDFLAG(ENABLE_SPEECH_SERVICE)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(blink::features::kDesktopPWAsSubApps) &&
       !render_frame_host->GetParentOrOuterDocument()) {
     // The service binder will reject non-primary main frames, but we still need
@@ -1137,7 +1137,7 @@ void PopulateChromeWebUIFrameBinders(
       commerce::CommerceInternalsUI>(map);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<
       connectors_internals::mojom::PageHandler,
       enterprise_connectors::ConnectorsInternalsUI>(map);
@@ -1148,7 +1148,7 @@ void PopulateChromeWebUIFrameBinders(
                                          policy::DlpInternalsUI>(map);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<
       app_management::mojom::PageHandlerFactory, WebAppSettingsUI>(map);
 #endif
@@ -1759,7 +1759,7 @@ void PopulateChromeWebUIFrameBinders(
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<discards::mojom::DetailsProvider,
                                          DiscardsUI>(map);
 
