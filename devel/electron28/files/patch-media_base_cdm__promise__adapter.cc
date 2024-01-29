--- media/base/cdm_promise_adapter.cc.orig	2023-08-10 01:48:46 UTC
+++ media/base/cdm_promise_adapter.cc
@@ -94,7 +94,13 @@ void CdmPromiseAdapter::RejectPromise(uint32_t promise
 void CdmPromiseAdapter::Clear(ClearReason reason) {
   // Reject all outstanding promises.
   DCHECK(thread_checker_.CalledOnValidThread());
+#if defined(__clang__) && (__clang_major__ >= 16)
   for (auto& [promise_id, promise] : promises_) {
+#else
+  for (auto& [p_i, p_e] : promises_) {
+    auto& promise_id = p_i;
+    auto& promise = p_e;
+#endif
     TRACE_EVENT_NESTABLE_ASYNC_END1(
         "media", "CdmPromise", TRACE_ID_WITH_SCOPE("CdmPromise", promise_id),
         "status", "cleared");
