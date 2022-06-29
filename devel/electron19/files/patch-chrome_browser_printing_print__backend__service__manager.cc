--- chrome/browser/printing/print_backend_service_manager.cc.orig	2022-06-19 00:44:35 UTC
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -480,7 +480,7 @@ absl::optional<uint32_t> PrintBackendServiceManager::R
       query_clients_.insert(client_id);
       break;
     case ClientType::kQueryWithUi:
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
       if (!query_with_ui_clients_.empty())
         return absl::nullopt;
 #endif
@@ -705,7 +705,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       break;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (query_with_ui_clients_.size() > 1)
         return absl::nullopt;
@@ -762,7 +762,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (!query_with_ui_clients_.empty())
         return absl::nullopt;
