--- chrome/browser/enterprise/browser_management/browser_management_service.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/enterprise/browser_management/browser_management_service.cc
@@ -61,7 +61,7 @@ BrowserManagementService::BrowserManagementService(Pro
       management_status_providers().end(),
       [](const auto& provider) { return provider->RequiresCache(); }));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::SequencedTaskRunner::GetCurrentDefault()->PostTask(
       FROM_HERE,
       base::BindOnce(&BrowserManagementService::UpdateManagementIconForProfile,
@@ -85,7 +85,7 @@ ui::ImageModel* BrowserManagementService::GetManagemen
 }
 
 ui::ImageModel* BrowserManagementService::GetManagementIconForProfile() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return management_icon_for_profile_.IsEmpty() ? nullptr
                                                 : &management_icon_for_profile_;
 #else
@@ -94,7 +94,7 @@ gfx::Image* BrowserManagementService::GetManagementIco
 }
 
 gfx::Image* BrowserManagementService::GetManagementIconForBrowser() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return management_icon_for_browser_.IsEmpty() ? nullptr
                                                 : &management_icon_for_browser_;
 #else
@@ -107,7 +107,7 @@ void BrowserManagementService::TriggerPolicyStatusChan
   OnPolicyStatusChanged();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserManagementService::SetBrowserManagementIconForTesting(
     const gfx::Image& management_icon) {
   CHECK_IS_TEST();
@@ -196,7 +196,7 @@ void BrowserManagementService::OnPolicyStatusChanged()
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 void BrowserManagementService::OnPolicyStatusChanged() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   NotifyEnterpriseLabelUpdated();
 #endif
 }
