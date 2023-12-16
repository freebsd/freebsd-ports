--- content/browser/service_worker/service_worker_context_wrapper.cc.orig	2023-10-25 09:13:45 UTC
+++ content/browser/service_worker/service_worker_context_wrapper.cc
@@ -1409,7 +1409,12 @@ void ServiceWorkerContextWrapper::MaybeProcessPendingW
     return;
   }
 
+#if defined(__clang__) && (__clang_major__ >= 16)
   auto [document_url, key, callback] = std::move(*request);
+#else
+  auto [d_u, key, callback] = std::move(*request);
+  auto document_url = d_u;
+#endif
 
   DCHECK(document_url.is_valid());
   TRACE_EVENT1("ServiceWorker",
