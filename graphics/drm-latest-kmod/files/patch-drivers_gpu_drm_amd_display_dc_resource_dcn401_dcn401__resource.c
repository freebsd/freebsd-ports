--- drivers/gpu/drm/amd/display/dc/resource/dcn401/dcn401_resource.c.orig	2026-05-01 15:43:42 UTC
+++ drivers/gpu/drm/amd/display/dc/resource/dcn401/dcn401_resource.c
@@ -1611,10 +1611,13 @@ bool dcn401_validate_bandwidth(struct dc *dc,
 		bool fast_validate)
 {
 	bool out = false;
-	if (dc->debug.using_dml2)
+	if (dc->debug.using_dml2) {
+		DC_FP_START();
 		out = dml2_validate(dc, context,
 				context->power_source == DC_POWER_SOURCE_DC ? context->bw_ctx.dml2_dc_power_source : context->bw_ctx.dml2,
 				fast_validate);
+		DC_FP_END();
+	}
 	return out;
 }
 
