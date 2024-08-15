--- chrome/browser/ui/webui/management/management_ui_handler.h.orig	2024-06-18 21:43:25 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.h
@@ -31,7 +31,7 @@ class PolicyService;
 class PolicyService;
 }  // namespace policy
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace device_signals {
 class UserPermissionService;
 }  // namespace device_signals
@@ -72,7 +72,7 @@ class ManagementUIHandler : public content::WebUIMessa
   base::Value::List GetManagedWebsitesInfo(Profile* profile) const;
   base::Value::List GetApplicationsInfo(Profile* profile) const;
   virtual policy::PolicyService* GetPolicyService();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual device_signals::UserPermissionService* GetUserPermissionService();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
