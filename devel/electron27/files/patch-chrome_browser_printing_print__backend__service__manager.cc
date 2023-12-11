--- chrome/browser/printing/print_backend_service_manager.cc.orig	2023-10-19 19:58:05 UTC
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -33,7 +33,7 @@
 #include "printing/buildflags/buildflags.h"
 #include "printing/printing_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #endif
 
@@ -851,7 +851,7 @@ PrintBackendServiceManager::GetServiceFromBundle(
         host.BindNewPipeAndPassReceiver(),
         content::ServiceProcessHost::Options()
             .WithDisplayName(IDS_UTILITY_PROCESS_PRINT_BACKEND_SERVICE_NAME)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
             .WithExtraCommandLineSwitches({switches::kMessageLoopTypeUi})
 #endif
             .Pass());
@@ -1024,7 +1024,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (HasQueryWithUiClientForRemoteId(remote_id)) {
         return absl::nullopt;
