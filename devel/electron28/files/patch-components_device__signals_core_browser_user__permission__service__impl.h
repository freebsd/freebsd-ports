--- components/device_signals/core/browser/user_permission_service_impl.h.orig	2023-08-10 01:48:40 UTC
+++ components/device_signals/core/browser/user_permission_service_impl.h
@@ -39,7 +39,7 @@ class UserPermissionServiceImpl : public UserPermissio
 
   // UserPermissionService:
   bool ShouldCollectConsent() const override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UserPermission CanUserCollectSignals(
       const UserContext& user_context) const override;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX
