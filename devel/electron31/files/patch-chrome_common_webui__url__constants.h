--- chrome/common/webui_url_constants.h.orig	2024-06-18 21:43:25 UTC
+++ chrome/common/webui_url_constants.h
@@ -437,23 +437,23 @@ extern const char kOsUIVersionURL[];
 extern const char kOsUIVersionURL[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kChromeUIWebUIJsErrorHost[];
 extern const char kChromeUIWebUIJsErrorURL[];
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 extern const char kChromeUIConnectorsInternalsHost[];
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kChromeUIDiscardsHost[];
 extern const char kChromeUIDiscardsURL[];
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kChromeUIWebAppSettingsURL[];
 extern const char kChromeUIWebAppSettingsHost[];
 #endif
@@ -468,14 +468,14 @@ extern const char kChromeUILinuxProxyConfigHost[];
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 extern const char kChromeUISandboxHost[];
 #endif
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 extern const char kChromeUIBrowserSwitchHost[];
 extern const char kChromeUIBrowserSwitchURL[];
 extern const char kChromeUIIntroHost[];
@@ -491,7 +491,7 @@ extern const char kChromeUIProfilePickerStartupQuery[]
 extern const char kChromeUIProfilePickerStartupQuery[];
 #endif
 
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
      defined(TOOLKIT_VIEWS)) ||                         \
     defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogHost[];
