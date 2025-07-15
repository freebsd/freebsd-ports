--- chrome/browser/safe_browsing/chrome_password_protection_service.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/safe_browsing/chrome_password_protection_service.cc
@@ -1269,7 +1269,7 @@ std::string ChromePasswordProtectionService::GetOrgani
     ReusedPasswordAccountType password_type) const {
   if (base::FeatureList::IsEnabled(
           safe_browsing::kEnterprisePasswordReuseUiRefresh)) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return GetPrefs()->GetString(prefs::kEnterpriseCustomLabelForProfile);
 #else
     return std::string();
