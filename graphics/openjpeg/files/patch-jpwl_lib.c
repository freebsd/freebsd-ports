--- jpwl/jpwl_lib.c.orig	2007-11-29 15:38:26.000000000 +0100
+++ jpwl/jpwl_lib.c	2009-03-21 12:39:09.000000000 +0100
@@ -166,7 +166,7 @@
 			/* Add this marker to the 'insertanda' list */
 			if (*jwmarker_num < JPWL_MAX_NO_MARKERS) {
 				jwmarker[*jwmarker_num].id = J2K_MS_EPB; /* its type */
-				jwmarker[*jwmarker_num].epbmark = epb_mark; /* the EPB */
+				jwmarker[*jwmarker_num].u.epbmark = epb_mark; /* the EPB */
 				jwmarker[*jwmarker_num].pos = (int) place_pos; /* after SOT */
 				jwmarker[*jwmarker_num].dpos = place_pos + 0.0000001 * (double)(*idx); /* not very first! */
 				jwmarker[*jwmarker_num].len = epb_mark->Lepb; /* its length */
@@ -335,7 +335,7 @@
 	jpwl_epc_ms_t *epc = NULL;
 
 	/* Alloc space */
-	if (!(epc = (jpwl_epc_ms_t *) malloc((size_t) 1 * sizeof (jpwl_epc_ms_t)))) {
+	if (!(epc = (jpwl_epc_ms_t *) opj_aligned_malloc((size_t) 1 * sizeof (jpwl_epc_ms_t)))) {
 		opj_event_msg(j2k->cinfo, EVT_ERROR, "Could not allocate room for EPC MS\n");
 		return NULL;
 	};
@@ -1196,7 +1196,7 @@
 	jpwl_esd_ms_t *esd = NULL;
 
 	/* Alloc space */
-	if (!(esd = (jpwl_esd_ms_t *) malloc((size_t) 1 * sizeof (jpwl_esd_ms_t)))) {
+	if (!(esd = (jpwl_esd_ms_t *) opj_aligned_malloc((size_t) 1 * sizeof (jpwl_esd_ms_t)))) {
 		opj_event_msg(j2k->cinfo, EVT_ERROR, "Could not allocate room for ESD MS\n");
 		return NULL;
 	};
