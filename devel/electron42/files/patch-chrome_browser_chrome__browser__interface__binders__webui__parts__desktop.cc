--- chrome/browser/chrome_browser_interface_binders_webui_parts_desktop.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/chrome_browser_interface_binders_webui_parts_desktop.cc
@@ -139,7 +139,7 @@
 #include "ui/webui/resources/js/browser_command/browser_command.mojom.h"
 #include "ui/webui/resources/js/tracked_element/tracked_element.mojom.h"  // nogncheck crbug.com/1125897
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/app_home/app_home.mojom.h"
 #include "chrome/browser/ui/webui/app_home/app_home_ui.h"
 #include "chrome/browser/ui/webui/app_settings/web_app_settings_ui.h"
@@ -362,7 +362,7 @@ void PopulateChromeWebUIFrameBindersPartsDesktop(
         HistoryClustersSidePanelUI, NewTabPageUI, BookmarksSidePanelUI>(map);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<whats_new::mojom::PageHandlerFactory,
                                          WhatsNewUI>(map);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -374,7 +374,7 @@ void PopulateChromeWebUIFrameBindersPartsDesktop(
 
   RegisterWebUIControllerInterfaceBinder<
       browser_command::mojom::CommandHandlerFactory,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       WhatsNewUI,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
       NewTabPageUI>(map);
@@ -593,7 +593,7 @@ void PopulateChromeWebUIFrameBindersPartsDesktop(
         OmniboxPopupUI>(map);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<
       app_management::mojom::PageHandlerFactory, WebAppSettingsUI>(map);
 
@@ -615,7 +615,7 @@ void PopulateChromeWebUIFrameBindersPartsDesktop(
         private_ai::PrivateAiInternalsUI>(map);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<updater_ui::mojom::PageHandlerFactory,
                                          UpdaterUI>(map);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
