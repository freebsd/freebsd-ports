--- chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc.orig	2024-06-18 21:43:25 UTC
+++ chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc
@@ -136,7 +136,7 @@
 #include "chrome/browser/ui/chrome_pages.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_LACROS)
 #include "ui/display/screen.h"
 #endif
 
@@ -155,7 +155,7 @@
 #include "chrome/browser/ui/webui/certificate_manager_localized_strings_provider.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui_factory.h"
 #include "ui/ozone/public/ozone_platform.h"
 #endif
@@ -272,7 +272,7 @@ void AddA11yStrings(content::WebUIDataSource* html_sou
       {"focusHighlightLabel",
        IDS_SETTINGS_ACCESSIBILITY_FOCUS_HIGHLIGHT_DESCRIPTION},
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       {"overscrollHistoryNavigationTitle",
        IDS_SETTINGS_OVERSCROLL_HISTORY_NAVIGATION_TITLE},
       {"overscrollHistoryNavigationSubtitle",
@@ -412,7 +412,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
       {"huge", IDS_SETTINGS_HUGE_FONT_SIZE},
       {"sidePanelAlignLeft", IDS_SETTINGS_SIDE_PANEL_ALIGN_LEFT},
       {"sidePanelAlignRight", IDS_SETTINGS_SIDE_PANEL_ALIGN_RIGHT},
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"gtkTheme", IDS_SETTINGS_GTK_THEME},
       {"useGtkTheme", IDS_SETTINGS_USE_GTK_THEME},
       {"qtTheme", IDS_SETTINGS_QT_THEME},
@@ -422,7 +422,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
 #else
       {"resetToDefaultTheme", IDS_SETTINGS_RESET_TO_DEFAULT_THEME},
 #endif
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_LACROS)
       {"showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS},
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -445,7 +445,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   bool show_custom_chrome_frame = ui::OzonePlatform::GetInstance()
                                       ->GetPlatformRuntimeProperties()
                                       .supports_server_side_window_decorations;
