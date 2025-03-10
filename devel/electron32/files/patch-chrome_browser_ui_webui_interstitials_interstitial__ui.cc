--- chrome/browser/ui/webui/interstitials/interstitial_ui.cc.orig	2024-08-14 20:54:41 UTC
+++ chrome/browser/ui/webui/interstitials/interstitial_ui.cc
@@ -70,7 +70,7 @@
 #include "components/security_interstitials/content/captive_portal_blocking_page.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page.h"
 #endif
@@ -376,7 +376,7 @@ std::unique_ptr<EnterpriseWarnPage> CreateEnterpriseWa
                                                        kRequestUrl));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::unique_ptr<SupervisedUserVerificationPage>
 CreateSupervisedUserVerificationPage(content::WebContents* web_contents) {
   const GURL kRequestUrl("https://supervised-user-verification.example.net");
@@ -570,7 +570,7 @@ void InterstitialHTMLSource::StartDataRequest(
     interstitial_delegate = CreateInsecureFormPage(web_contents);
   } else if (path_without_query == "/https_only") {
     interstitial_delegate = CreateHttpsOnlyModePage(web_contents);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (path_without_query == "/supervised-user-verify") {
     interstitial_delegate = CreateSupervisedUserVerificationPage(web_contents);
 #endif
