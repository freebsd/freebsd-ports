--- chrome/browser/global_features.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/global_features.cc
@@ -36,7 +36,7 @@
 #include "chrome/browser/background/glic/glic_background_mode_manager.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This causes a gn error on Android builds, because gn does not understand
 // buildflags, so we include it only on platforms where it is used.
 #include "chrome/browser/default_browser/default_browser_manager.h"
@@ -156,7 +156,7 @@ void GlobalFeatures::PostBrowserProcessInitCore() {
 
 void GlobalFeatures::PostBrowserProcessInitCore() {
   system_permissions_platform_handle_ = CreateSystemPermissionsPlatformHandle();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/463742800): Migrate WhatsNewRegistry (and other non-core
   // features) to Init().
   whats_new_registry_ = CreateWhatsNewRegistry();
@@ -224,7 +224,7 @@ void GlobalFeatures::PostMainMessageLoopRun() {
 
   application_advanced_protection_status_detector_.reset();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DefaultBrowserPromptManager::GetInstance()->CloseAllPrompts(
       DefaultBrowserPromptManager::CloseReason::kDismiss);
 #endif
@@ -245,7 +245,7 @@ GlobalFeatures::CreateSystemPermissionsPlatformHandle(
   return system_permission_settings::PlatformHandle::Create();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<whats_new::WhatsNewRegistry>
 GlobalFeatures::CreateWhatsNewRegistry() {
   return whats_new::CreateWhatsNewRegistry();
