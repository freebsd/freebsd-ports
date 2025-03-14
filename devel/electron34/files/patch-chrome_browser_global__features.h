--- chrome/browser/global_features.h.orig	2024-10-16 21:30:58 UTC
+++ chrome/browser/global_features.h
@@ -14,7 +14,7 @@ namespace whats_new {
 class PlatformHandle;
 }  // namespace system_permission_settings
 namespace whats_new {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class WhatsNewRegistry;
 #endif
 }  // namespace whats_new
@@ -45,7 +45,7 @@ class GlobalFeatures {
   system_permissions_platform_handle() {
     return system_permissions_platform_handle_.get();
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   whats_new::WhatsNewRegistry* whats_new_registry() {
     return whats_new_registry_.get();
   }
@@ -60,7 +60,7 @@ class GlobalFeatures {
 
   virtual std::unique_ptr<system_permission_settings::PlatformHandle>
   CreateSystemPermissionsPlatformHandle();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual std::unique_ptr<whats_new::WhatsNewRegistry> CreateWhatsNewRegistry();
 #endif
 
@@ -70,7 +70,7 @@ class GlobalFeatures {
 
   std::unique_ptr<system_permission_settings::PlatformHandle>
       system_permissions_platform_handle_;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<whats_new::WhatsNewRegistry> whats_new_registry_;
 #endif
 };
