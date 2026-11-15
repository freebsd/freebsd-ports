--- chrome/browser/ui/webui/user_education_internals/user_education_internals_page_handler_impl.cc.orig	2026-10-19 21:50:55 UTC
+++ chrome/browser/ui/webui/user_education_internals/user_education_internals_page_handler_impl.cc
@@ -52,7 +52,7 @@
 #include "ui/base/webui/resource_path.h"
 #include "ui/base/window_open_disposition.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/navigator/browser_navigator.h"
 #include "chrome/browser/ui/navigator/browser_navigator_params.h"
 #include "net/base/url_util.h"
@@ -92,7 +92,7 @@ whats_new::WhatsNewRegistry* GetWhatsNewRegistry() {
 }
 
 whats_new::WhatsNewRegistry* GetWhatsNewRegistry() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return g_browser_process->GetFeatures()->whats_new_registry();
 #else
   return nullptr;
@@ -940,7 +940,7 @@ void UserEducationInternalsPageHandlerImpl::LaunchWhat
 }
 
 void UserEducationInternalsPageHandlerImpl::LaunchWhatsNewStaging() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   GURL url = net::AppendQueryParameter(GURL(chrome::kChromeUIWhatsNewURL),
                                        "staging", "true");
   NavigateParams params(profile_, url, ui::PAGE_TRANSITION_TYPED);
