--- src/pipeline/pipeline.c.orig	2026-08-18 20:39:59 UTC
+++ src/pipeline/pipeline.c
@@ -934,6 +934,9 @@ static void predump_complexity(cbm_pipeline_ctx_t *ctx
 static void predump_complexity(cbm_pipeline_ctx_t *ctx) {
     cbm_pipeline_pass_complexity(ctx);
 }
+static void predump_sysctl(cbm_pipeline_ctx_t *ctx) {
+    cbm_pipeline_resolve_sysctl(ctx->gbuf);
+}
 static void run_predump_passes(cbm_pipeline_t *p, cbm_pipeline_ctx_t *ctx) {
     static const struct {
         predump_pass_fn fn;
@@ -943,8 +946,9 @@ static void run_predump_passes(cbm_pipeline_t *p, cbm_
         {predump_deco, "decorator_tags", false}, {predump_cfg, "configlink", false},
         {predump_route, "route_match", false},   {predump_sim, "similarity", true},
         {predump_sem, "semantic_edges", true},   {predump_complexity, "complexity", false},
+        {predump_sysctl, "sysctl_resolve", false},
     };
-    enum { PREDUMP_PASS_COUNT = 6 };
+    enum { PREDUMP_PASS_COUNT = 7 };
     struct timespec t;
     for (int i = 0; i < PREDUMP_PASS_COUNT && !check_cancel(p); i++) {
         /* "moderate_only" passes (similarity/semantic edges) run in FULL,
