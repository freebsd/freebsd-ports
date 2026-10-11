--- drivers/gpu/drm/amd/display/dc/core/dc_state.c.orig	2026-05-28 06:00:00 UTC
+++ drivers/gpu/drm/amd/display/dc/core/dc_state.c
@@ -210,14 +210,22 @@ struct dc_state *dc_state_create(struct dc *dc, struc

 #ifdef CONFIG_DRM_AMD_DC_FP
 	if (dc->debug.using_dml2) {
+		bool dml2_ok;
+
 		dml2_opt->use_clock_dc_limits = false;
-		if (!dml2_create(dc, dml2_opt, &state->bw_ctx.dml2)) {
+		DC_FP_START();
+		dml2_ok = dml2_create(dc, dml2_opt, &state->bw_ctx.dml2);
+		DC_FP_END();
+		if (!dml2_ok) {
 			dc_state_release(state);
 			return NULL;
 		}

 		dml2_opt->use_clock_dc_limits = true;
-		if (!dml2_create(dc, dml2_opt, &state->bw_ctx.dml2_dc_power_source)) {
+		DC_FP_START();
+		dml2_ok = dml2_create(dc, dml2_opt, &state->bw_ctx.dml2_dc_power_source);
+		DC_FP_END();
+		if (!dml2_ok) {
 			dc_state_release(state);
 			return NULL;
 		}
@@ -268,16 +276,28 @@ struct dc_state *dc_state_create_copy(struct dc_state
 	new_state->bw_ctx.dml2 = NULL;
 	new_state->bw_ctx.dml2_dc_power_source = NULL;

-	if (src_state->bw_ctx.dml2 &&
-			!dml2_create_copy(&new_state->bw_ctx.dml2, src_state->bw_ctx.dml2)) {
-		dc_state_release(new_state);
-		return NULL;
+	if (src_state->bw_ctx.dml2) {
+		bool dml2_ok;
+
+		DC_FP_START();
+		dml2_ok = dml2_create_copy(&new_state->bw_ctx.dml2, src_state->bw_ctx.dml2);
+		DC_FP_END();
+		if (!dml2_ok) {
+			dc_state_release(new_state);
+			return NULL;
+		}
 	}

-	if (src_state->bw_ctx.dml2_dc_power_source &&
-			!dml2_create_copy(&new_state->bw_ctx.dml2_dc_power_source, src_state->bw_ctx.dml2_dc_power_source)) {
-		dc_state_release(new_state);
-		return NULL;
+	if (src_state->bw_ctx.dml2_dc_power_source) {
+		bool dml2_ok;
+
+		DC_FP_START();
+		dml2_ok = dml2_create_copy(&new_state->bw_ctx.dml2_dc_power_source, src_state->bw_ctx.dml2_dc_power_source);
+		DC_FP_END();
+		if (!dml2_ok) {
+			dc_state_release(new_state);
+			return NULL;
+		}
 	}
 #endif
