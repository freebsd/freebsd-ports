--- src/pipeline/pipeline_internal.h.orig	2026-08-18 20:39:59 UTC
+++ src/pipeline/pipeline_internal.h
@@ -570,6 +570,13 @@ int cbm_pipeline_pass_definitions(cbm_pipeline_ctx_t *
 int cbm_pipeline_pass_definitions(cbm_pipeline_ctx_t *ctx, const cbm_file_info_t *files,
                                   int file_count);
 
+/* FreeBSD/DragonFly sysctl OID resolution (src/pipeline/pass_sysctl.c).
+ * emit_raw is called per file from the consume step; resolve is a graph-only
+ * predump pass. */
+void cbm_sysctl_emit_raw_for_file(cbm_pipeline_ctx_t *ctx, const CBMFileResult *result,
+                                  const char *rel);
+void cbm_pipeline_resolve_sysctl(cbm_gbuf_t *gb);
+
 int cbm_pipeline_pass_k8s(cbm_pipeline_ctx_t *ctx, const cbm_file_info_t *files, int file_count);
 
 int cbm_pipeline_pass_calls(cbm_pipeline_ctx_t *ctx, const cbm_file_info_t *files, int file_count);
