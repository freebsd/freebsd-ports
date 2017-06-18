# Partial revert of the following commit because the feature check fails on 10.x
# which disables HW accel on gen4+ (the new check occurs for gen6+ as well)

From 088449487ebcb72561d73ffb91c96302583445a8 Mon Sep 17 00:00:00 2001
From: Kenneth Graunke <kenneth@whitecape.org>
Date: Wed, 22 Mar 2017 15:20:51 -0700
Subject: i965: Require Kernel 3.6 for Gen4-5 platforms.

We've already required Kernel 3.6 on Gen6+ since Mesa 9.2 (May 2013,
commit 92d2f5acfadea672417b6785710c9e8b7f605e41).  It seems reasonable
to require it for Gen4-5 as well, bumping the requirement from 2.6.39.

This is necessary for glClientWaitSync with a timeout to work, which
is a feature we expose on Gen4-5.  Without it, we would fall back to an
infinite wait, which is pretty bad.

See kernel commit 172cf15d18889313bf2c3bfb81fcea08369274ef in 3.6+.

Reviewed-by: Matt Turner <mattst88@gmail.com>

diff --git a/src/mesa/drivers/dri/i965/intel_screen.c b/src/mesa/drivers/dri/i965/intel_screen.c
index c7f111d..bc998ab 100644
--- src/mesa/drivers/dri/i965/intel_screen.c
+++ src/mesa/drivers/dri/i965/intel_screen.c
@@ -1274,8 +1274,8 @@ intel_init_bufmgr(struct intel_screen *screen)
 
    drm_intel_bufmgr_gem_enable_fenced_relocs(screen->bufmgr);
 
-   if (!intel_get_boolean(screen, I915_PARAM_HAS_WAIT_TIMEOUT)) {
-      fprintf(stderr, "[%s: %u] Kernel 3.6 required.\n", __func__, __LINE__);
+   if (!intel_get_boolean(screen, I915_PARAM_HAS_RELAXED_DELTA)) {
+      fprintf(stderr, "[%s: %u] Kernel 2.6.39 required.\n", __func__, __LINE__);
       return false;
    }
 
-- 
cgit v0.10.2
