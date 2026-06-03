--- chrome/browser/enterprise/browser_management/browser_management_service.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/enterprise/browser_management/browser_management_service.cc
@@ -50,7 +50,7 @@ BrowserManagementService::BrowserManagementService(Pro
 
 BrowserManagementService::BrowserManagementService(Profile* profile)
     : ManagementService(GetManagementStatusProviders(profile)) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::SequencedTaskRunner::GetCurrentDefault()->PostTask(
       FROM_HERE,
       base::BindOnce(&BrowserManagementService::UpdateManagementIconForProfile,
@@ -74,7 +74,7 @@ ui::ImageModel* BrowserManagementService::GetManagemen
 }
 
 ui::ImageModel* BrowserManagementService::GetManagementIconForProfile() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return management_icon_for_profile_.IsEmpty() ? nullptr
                                                 : &management_icon_for_profile_;
 #else
@@ -83,7 +83,7 @@ gfx::Image* BrowserManagementService::GetManagementIco
 }
 
 gfx::Image* BrowserManagementService::GetManagementIconForBrowser() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return management_icon_for_browser_.IsEmpty() ? nullptr
                                                 : &management_icon_for_browser_;
 #else
@@ -96,7 +96,7 @@ void BrowserManagementService::TriggerPolicyStatusChan
   OnPolicyStatusChanged();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserManagementService::SetBrowserManagementIconForTesting(
     const gfx::Image& management_icon) {
   CHECK_IS_TEST();
@@ -183,7 +183,7 @@ void BrowserManagementService::OnPolicyStatusChanged()
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 void BrowserManagementService::OnPolicyStatusChanged() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   NotifyEnterpriseLabelUpdated();
 #endif
 }
