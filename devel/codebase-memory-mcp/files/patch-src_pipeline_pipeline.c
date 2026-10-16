--- src/pipeline/pipeline.c.orig	2026-10-16 05:39:05 UTC
+++ src/pipeline/pipeline.c
@@ -2007,6 +2007,9 @@ static void predump_complexity(cbm_pipeline_ctx_t *ctx
 static void predump_complexity(cbm_pipeline_ctx_t *ctx) {
     cbm_pipeline_pass_complexity(ctx);
 }
+static void predump_sysctl(cbm_pipeline_ctx_t *ctx) {
+    cbm_pipeline_resolve_sysctl(ctx->gbuf);
+}
 static void predump_ensemble(cbm_pipeline_ctx_t *ctx) {
     cbm_pipeline_pass_ensemble_routing(ctx);
 }
@@ -2277,6 +2280,7 @@ static void run_predump_passes(cbm_pipeline_t *p, cbm_
         {predump_sim, "similarity", PREDUMP_SKIP_FAST},
         {predump_sem, "semantic_edges", PREDUMP_FAST_DOC_CANDIDATES},
         {predump_complexity, "complexity", PREDUMP_EVERY_MODE},
+        {predump_sysctl, "sysctl_resolve", PREDUMP_EVERY_MODE},
         /* Importance runs LAST: it reads CALLS/USAGE (extraction) and TESTS
          * (pass_tests, which run_post_extraction runs before this loop), so
          * every edge type its score depends on already exists here. */
