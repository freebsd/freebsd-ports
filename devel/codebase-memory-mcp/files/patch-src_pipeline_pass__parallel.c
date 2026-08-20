--- src/pipeline/pass_parallel.c.orig	2026-08-18 20:39:59 UTC
+++ src/pipeline/pass_parallel.c
@@ -1343,6 +1343,7 @@ int cbm_build_registry_from_cache(cbm_pipeline_ctx_t *
 
         imports_edges += create_imports_edges(ctx, result, rel, namespace_map);
         create_channel_edges(ctx, result, rel);
+        cbm_sysctl_emit_raw_for_file(ctx, result, rel);
         cbm_pipeline_create_env_configures_for_file(ctx, result, rel);
     }
 
