--- src/pipeline/pass_definitions.c.orig	2026-09-15 17:16:24 UTC
+++ src/pipeline/pass_definitions.c
@@ -876,6 +876,7 @@ int cbm_pipeline_pass_definitions(cbm_pipeline_ctx_t *
              * map is available without the cache (single-file scope). */
             total_imports += create_import_edges_for_file(ctx, result, rel, NULL);
             create_channel_edges_for_file(ctx, result, rel);
+            cbm_sysctl_emit_raw_for_file(ctx, result, rel);
             cbm_pipeline_create_env_configures_for_file(ctx, result, rel);
             cbm_free_result(result);
         }
@@ -909,6 +910,7 @@ int cbm_pipeline_pass_definitions(cbm_pipeline_ctx_t *
             total_imports +=
                 create_import_edges_for_file(ctx, result, files[i].rel_path, namespace_map);
             create_channel_edges_for_file(ctx, result, files[i].rel_path);
+            cbm_sysctl_emit_raw_for_file(ctx, result, files[i].rel_path);
             cbm_pipeline_create_env_configures_for_file(ctx, result, files[i].rel_path);
         }
         cbm_pipeline_namespace_map_free(namespace_map);
