--- chrome/browser/printing/print_backend_service_manager.cc.orig	2023-05-25 00:41:43 UTC
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -687,7 +687,7 @@ PrintBackendServiceManager::RegisterClient(
       query_clients_.insert(client_id);
       break;
     case ClientType::kQueryWithUi:
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
       if (!query_with_ui_clients_.empty())
         return absl::nullopt;
 #endif
@@ -960,7 +960,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       break;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (query_with_ui_clients_.size() > 1)
         return absl::nullopt;
@@ -1017,7 +1017,7 @@ PrintBackendServiceManager::DetermineIdleTimeoutUpdate
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (HasQueryWithUiClientForRemoteId(remote_id)) {
         return absl::nullopt;
@@ -1477,7 +1477,7 @@ template <class... T>
 void PrintBackendServiceManager::RunSavedCallbacks(
     RemoteSavedCallbacks<T...>& saved_callbacks,
     const RemoteId& remote_id,
-    std::remove_reference<T>::type... result) {
+    typename std::remove_reference<T>::type... result) {
   auto found_callbacks_map = saved_callbacks.find(remote_id);
   if (found_callbacks_map == saved_callbacks.end())
     return;  // No callbacks to run.
