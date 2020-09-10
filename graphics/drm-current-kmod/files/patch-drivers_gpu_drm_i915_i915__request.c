--- drivers/gpu/drm/i915/i915_request.c.orig	2020-09-10 16:18:40 UTC
+++ drivers/gpu/drm/i915/i915_request.c
@@ -492,7 +492,9 @@ void __i915_request_unsubmit(struct i915_request *requ
 #endif
 
 	GEM_BUG_ON(!irqs_disabled());
+#ifdef __freebsd_notyet__
 	lockdep_assert_held(&engine->active.lock);
+#endif
 
 	/*
 	 * Only unwind in reverse order, required so that the per-context list
