--- src/pipeline/pass_definitions.c.orig	2026-10-16 05:39:05 UTC
+++ src/pipeline/pass_definitions.c
@@ -1040,6 +1040,7 @@ int cbm_pipeline_pass_definitions(cbm_pipeline_ctx_t *
              * map is available without the cache (single-file scope). */
             total_imports += create_import_edges_for_file(ctx, result, rel, NULL);
             create_channel_edges_for_file(ctx, result, rel);
+            cbm_sysctl_emit_raw_for_file(ctx, result, rel);
             cbm_pipeline_diagram_arrows(ctx, result);
             cbm_pipeline_create_env_configures_for_file(ctx, result, rel);
             cbm_free_result(result);
@@ -1074,6 +1075,7 @@ int cbm_pipeline_pass_definitions(cbm_pipeline_ctx_t *
             total_imports +=
                 create_import_edges_for_file(ctx, result, files[i].rel_path, namespace_map);
             create_channel_edges_for_file(ctx, result, files[i].rel_path);
+            cbm_sysctl_emit_raw_for_file(ctx, result, files[i].rel_path);
             cbm_pipeline_diagram_arrows(ctx, result);
             cbm_pipeline_create_env_configures_for_file(ctx, result, files[i].rel_path);
         }
