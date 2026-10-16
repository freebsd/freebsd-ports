--- src/pipeline/pass_parallel.c.orig	2026-10-16 05:39:05 UTC
+++ src/pipeline/pass_parallel.c
@@ -1996,6 +1996,7 @@ int cbm_build_registry_from_cache(cbm_pipeline_ctx_t *
 
         imports_edges += create_imports_edges(ctx, result, rel, namespace_map);
         create_channel_edges(ctx, result, rel);
+        cbm_sysctl_emit_raw_for_file(ctx, result, rel);
         cbm_pipeline_diagram_arrows(ctx, result);
         cbm_pipeline_create_env_configures_for_file(ctx, result, rel);
         if (loaded) {
