--- src/libjasper/jpc/jpc_enc.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_enc.c	2013-04-17 22:32:23.000000000 +0200
@@ -403,7 +403,7 @@
 		vsteplcm *= jas_image_cmptvstep(image, cmptno);
 	}
 
-	if (!(cp->ccps = jas_malloc(cp->numcmpts * sizeof(jpc_enc_ccp_t)))) {
+	if (!(cp->ccps = jas_malloc2(cp->numcmpts, sizeof(jpc_enc_ccp_t)))) {
 		goto error;
 	}
 	for (cmptno = 0, ccp = cp->ccps; cmptno < JAS_CAST(int, cp->numcmpts); ++cmptno,
@@ -656,7 +656,7 @@
 
 	if (ilyrrates && numilyrrates > 0) {
 		tcp->numlyrs = numilyrrates + 1;
-		if (!(tcp->ilyrrates = jas_malloc((tcp->numlyrs - 1) *
+		if (!(tcp->ilyrrates = jas_malloc2((tcp->numlyrs - 1),
 		  sizeof(jpc_fix_t)))) {
 			goto error;
 		}
@@ -940,7 +940,7 @@
 	siz->tilewidth = cp->tilewidth;
 	siz->tileheight = cp->tileheight;
 	siz->numcomps = cp->numcmpts;
-	siz->comps = jas_malloc(siz->numcomps * sizeof(jpc_sizcomp_t));
+	siz->comps = jas_malloc2(siz->numcomps, sizeof(jpc_sizcomp_t));
 	assert(siz->comps);
 	for (i = 0; i < JAS_CAST(int, cp->numcmpts); ++i) {
 		siz->comps[i].prec = cp->ccps[i].prec;
@@ -977,7 +977,7 @@
 		return -1;
 	}
 	crg = &enc->mrk->parms.crg;
-	crg->comps = jas_malloc(crg->numcomps * sizeof(jpc_crgcomp_t));
+	crg->comps = jas_malloc2(crg->numcomps, sizeof(jpc_crgcomp_t));
 	if (jpc_putms(enc->out, enc->cstate, enc->mrk)) {
 		jas_eprintf("cannot write CRG marker\n");
 		return -1;
@@ -1955,7 +1955,7 @@
 	tile->mctid = cp->tcp.mctid;
 
 	tile->numlyrs = cp->tcp.numlyrs;
-	if (!(tile->lyrsizes = jas_malloc(tile->numlyrs *
+	if (!(tile->lyrsizes = jas_malloc2(tile->numlyrs,
 	  sizeof(uint_fast32_t)))) {
 		goto error;
 	}
@@ -1964,7 +1964,7 @@
 	}
 
 	/* Allocate an array for the per-tile-component information. */
-	if (!(tile->tcmpts = jas_malloc(cp->numcmpts * sizeof(jpc_enc_tcmpt_t)))) {
+	if (!(tile->tcmpts = jas_malloc2(cp->numcmpts, sizeof(jpc_enc_tcmpt_t)))) {
 		goto error;
 	}
 	/* Initialize a few members critical for error recovery. */
@@ -2110,7 +2110,7 @@
 	  jas_seq2d_ystart(tcmpt->data), jas_seq2d_xend(tcmpt->data),
 	  jas_seq2d_yend(tcmpt->data), bandinfos);
 
-	if (!(tcmpt->rlvls = jas_malloc(tcmpt->numrlvls * sizeof(jpc_enc_rlvl_t)))) {
+	if (!(tcmpt->rlvls = jas_malloc2(tcmpt->numrlvls, sizeof(jpc_enc_rlvl_t)))) {
 		goto error;
 	}
 	for (rlvlno = 0, rlvl = tcmpt->rlvls; rlvlno < tcmpt->numrlvls;
@@ -2213,7 +2213,7 @@
 	rlvl->numvprcs = JPC_FLOORDIVPOW2(brprcbry - tlprctly, rlvl->prcheightexpn);
 	rlvl->numprcs = rlvl->numhprcs * rlvl->numvprcs;
 
-	if (!(rlvl->bands = jas_malloc(rlvl->numbands * sizeof(jpc_enc_band_t)))) {
+	if (!(rlvl->bands = jas_malloc2(rlvl->numbands, sizeof(jpc_enc_band_t)))) {
 		goto error;
 	}
 	for (bandno = 0, band = rlvl->bands; bandno < rlvl->numbands;
@@ -2290,7 +2290,7 @@
 	band->synweight = bandinfo->synenergywt;
 
 if (band->data) {
-	if (!(band->prcs = jas_malloc(rlvl->numprcs * sizeof(jpc_enc_prc_t)))) {
+	if (!(band->prcs = jas_malloc2(rlvl->numprcs, sizeof(jpc_enc_prc_t)))) {
 		goto error;
 	}
 	for (prcno = 0, prc = band->prcs; prcno < rlvl->numprcs; ++prcno,
@@ -2422,7 +2422,7 @@
 			goto error;
 		}
 
-		if (!(prc->cblks = jas_malloc(prc->numcblks * sizeof(jpc_enc_cblk_t)))) {
+		if (!(prc->cblks = jas_malloc2(prc->numcblks, sizeof(jpc_enc_cblk_t)))) {
 			goto error;
 		}
 		for (cblkno = 0, cblk = prc->cblks; cblkno < prc->numcblks;
