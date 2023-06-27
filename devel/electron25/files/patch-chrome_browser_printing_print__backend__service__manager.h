--- chrome/browser/printing/print_backend_service_manager.h.orig	2023-05-25 00:41:43 UTC
+++ chrome/browser/printing/print_backend_service_manager.h
@@ -587,7 +587,7 @@ class PrintBackendServiceManager {
   template <class... T>
   void RunSavedCallbacks(RemoteSavedCallbacks<T...>& saved_callbacks,
                          const RemoteId& remote_id,
-                         std::remove_reference<T>::type... result);
+                         typename std::remove_reference<T>::type... result);
 
   // Test support for client ID management.
   static void SetClientsForTesting(
