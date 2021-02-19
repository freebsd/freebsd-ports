--- intern/cycles/util/util_tbb.h.orig	2021-01-23 14:10:16 UTC
+++ intern/cycles/util/util_tbb.h
@@ -36,7 +36,14 @@ using tbb::parallel_for;

 static inline void parallel_for_cancel()
 {
+#if TBB_INTERFACE_VERSION_MAJOR >= 12
+  tbb::task_group_context *ctx = tbb::task::current_context();
+  if (ctx) {
+    ctx->cancel_group_execution();
+  }
+#else
   tbb::task::self().cancel_group_execution();
+#endif
 }

 CCL_NAMESPACE_END
