--- src/lib/openjp2/tcd.c.orig	2016-09-14 00:02:27 UTC
+++ src/lib/openjp2/tcd.c
@@ -706,9 +706,20 @@ static INLINE OPJ_BOOL opj_tcd_init_tile
 	l_tx0 = l_cp->tx0 + p * l_cp->tdx; /* can't be greater than l_image->x1 so won't overflow */
 	l_tile->x0 = (OPJ_INT32)opj_uint_max(l_tx0, l_image->x0);
 	l_tile->x1 = (OPJ_INT32)opj_uint_min(opj_uint_adds(l_tx0, l_cp->tdx), l_image->x1);
+	/* all those OPJ_UINT32 are casted to OPJ_INT32, let's do some sanity check */
+	if ((l_tile->x0 < 0) || (l_tile->x1 <= l_tile->x0)) {
+		opj_event_msg(manager, EVT_ERROR, "Tile X coordinates are not supported\n");
+		return OPJ_FALSE;
+	}
 	l_ty0 = l_cp->ty0 + q * l_cp->tdy; /* can't be greater than l_image->y1 so won't overflow */
 	l_tile->y0 = (OPJ_INT32)opj_uint_max(l_ty0, l_image->y0);
 	l_tile->y1 = (OPJ_INT32)opj_uint_min(opj_uint_adds(l_ty0, l_cp->tdy), l_image->y1);
+	/* all those OPJ_UINT32 are casted to OPJ_INT32, let's do some sanity check */
+	if ((l_tile->y0 < 0) || (l_tile->y1 <= l_tile->y0)) {
+		opj_event_msg(manager, EVT_ERROR, "Tile Y coordinates are not supported\n");
+		return OPJ_FALSE;
+	}
+	
 
 	/* testcase 1888.pdf.asan.35.988 */
 	if (l_tccp->numresolutions == 0) {
