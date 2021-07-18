--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2021-04-14 01:08:42 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -242,7 +242,7 @@
 #include "chrome/browser/ui/webui/app_launcher_page_ui.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/webui_js_error/webui_js_error_ui.h"
 #endif
 
@@ -263,12 +263,12 @@
 #include "chrome/browser/ui/webui/conflicts/conflicts_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_ANDROID)
 #include "chrome/browser/ui/webui/sandbox/sandbox_internals_ui.h"
 #endif
@@ -465,7 +465,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost
 #endif
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -811,7 +811,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
   }
 #endif  // !defined(OFFICIAL_BUILD)
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUIWebUIJsErrorHost)
     return &NewWebUI<WebUIJsErrorUI>;
 #endif
@@ -873,7 +873,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
   if (url.host_piece() == chrome::kChromeUINaClHost)
     return &NewWebUI<NaClUI>;
 #endif
-#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(TOOLKIT_VIEWS)) || \
+#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(TOOLKIT_VIEWS)) || defined(OS_BSD) || \
     defined(USE_AURA)
   if (url.host_piece() == chrome::kChromeUITabModalConfirmDialogHost)
     return &NewWebUI<ConstrainedWebDialogUI>;
@@ -917,13 +917,13 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
     return &NewWebUI<media_router::MediaRouterInternalsUI>;
   }
 #endif
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_ANDROID)
   if (url.host_piece() == chrome::kChromeUISandboxHost) {
     return &NewWebUI<SandboxInternalsUI>;
   }
 #endif
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   if (url.host_piece() == chrome::kChromeUIDiscardsHost)
     return &NewWebUI<DiscardsUI>;
@@ -931,7 +931,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   if (url.host_piece() == chrome::kChromeUIBrowserSwitchHost)
     return &NewWebUI<BrowserSwitchUI>;
 #endif
