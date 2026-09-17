--- src/pipeline/pipeline.c.orig	2026-09-16 19:50:09 UTC
+++ src/pipeline/pipeline.c
@@ -1032,6 +1032,9 @@ static void predump_complexity(cbm_pipeline_ctx_t *ctx
 static void predump_complexity(cbm_pipeline_ctx_t *ctx) {
     cbm_pipeline_pass_complexity(ctx);
 }
+static void predump_sysctl(cbm_pipeline_ctx_t *ctx) {
+    cbm_pipeline_resolve_sysctl(ctx->gbuf);
+}
 static void predump_ensemble(cbm_pipeline_ctx_t *ctx) {
     cbm_pipeline_pass_ensemble_routing(ctx);
 }
@@ -1268,6 +1271,7 @@ static void run_predump_passes(cbm_pipeline_t *p, cbm_
         {predump_sim, "similarity", true},
         {predump_sem, "semantic_edges", true},
         {predump_complexity, "complexity", false},
+        {predump_sysctl, "sysctl_resolve", false},
         /* Importance runs LAST: it reads CALLS/USAGE (extraction) and TESTS
          * (pass_tests, which run_post_extraction runs before this loop), so
          * every edge type its score depends on already exists here. */
