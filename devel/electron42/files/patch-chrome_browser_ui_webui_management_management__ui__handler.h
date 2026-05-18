--- chrome/browser/ui/webui/management/management_ui_handler.h.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.h
@@ -33,7 +33,7 @@ class GetUserEligiblePromotionsResponse;
 class GetUserEligiblePromotionsResponse;
 }  // namespace enterprise_management
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace device_signals {
 class UserPermissionService;
 }  // namespace device_signals
@@ -90,7 +90,7 @@ class ManagementUIHandler : public content::WebUIMessa
   base::ListValue GetManagedWebsitesInfo(Profile* profile) const;
   base::ListValue GetApplicationsInfo(Profile* profile) const;
   virtual policy::PolicyService* GetPolicyService();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual device_signals::UserPermissionService* GetUserPermissionService();
   base::DictValue GetDeviceSignalGrantedMessage();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
