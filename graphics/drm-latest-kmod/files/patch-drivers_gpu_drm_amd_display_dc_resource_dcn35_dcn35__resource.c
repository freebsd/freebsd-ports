--- drivers/gpu/drm/amd/display/dc/resource/dcn35/dcn35_resource.c.orig	2026-05-01 15:43:42 UTC
+++ drivers/gpu/drm/amd/display/dc/resource/dcn35/dcn35_resource.c
@@ -1738,9 +1738,11 @@ static bool dcn35_validate_bandwidth(struct dc *dc,
 {
 	bool out = false;
 
+	DC_FP_START();
 	out = dml2_validate(dc, context,
 			context->power_source == DC_POWER_SOURCE_DC ? context->bw_ctx.dml2_dc_power_source : context->bw_ctx.dml2,
 			fast_validate);
+	DC_FP_END();
 
 	if (fast_validate)
 		return out;
