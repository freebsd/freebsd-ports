--- chrome/browser/permissions/chrome_permissions_client.cc.orig	2024-02-21 00:20:35 UTC
+++ chrome/browser/permissions/chrome_permissions_client.cc
@@ -225,7 +225,7 @@ bool ChromePermissionsClient::IsCookieDeletionDisabled
 bool ChromePermissionsClient::IsCookieDeletionDisabled(
     content::BrowserContext* browser_context,
     const GURL& origin) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(
           supervised_user::kClearingCookiesKeepsSupervisedUsersSignedIn)) {
     return false;
