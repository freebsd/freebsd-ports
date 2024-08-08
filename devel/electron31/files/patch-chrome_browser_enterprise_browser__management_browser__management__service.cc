--- chrome/browser/enterprise/browser_management/browser_management_service.cc.orig	2024-04-15 20:33:46 UTC
+++ chrome/browser/enterprise/browser_management/browser_management_service.cc
@@ -21,7 +21,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void UpdateEnterpriseLogo(
     Profile* profile,
     base::OnceCallback<void(const gfx::Image&,
@@ -98,7 +98,7 @@ BrowserManagementMetadata::BrowserManagementMetadata(P
 }  // namespace
 
 BrowserManagementMetadata::BrowserManagementMetadata(Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UpdateManagementLogo(profile);
   pref_change_registrar_.Init(profile->GetPrefs());
   pref_change_registrar_.Add(
@@ -114,7 +114,7 @@ const gfx::Image& BrowserManagementMetadata::GetManage
   return management_logo_;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserManagementMetadata::UpdateManagementLogo(Profile* profile) {
   UpdateEnterpriseLogo(
       profile, base::BindOnce(&BrowserManagementMetadata::SetManagementLogo,
