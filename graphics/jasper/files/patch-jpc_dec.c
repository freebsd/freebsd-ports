--- src/libjasper/jpc/jpc_dec.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_dec.c	2016-02-20 13:49:45.581508000 +0100
@@ -449,7 +449,7 @@
 
 	if (dec->state == JPC_MH) {
 
-		compinfos = jas_malloc(dec->numcomps * sizeof(jas_image_cmptparm_t));
+		compinfos = jas_malloc2(dec->numcomps, sizeof(jas_image_cmptparm_t));
 		assert(compinfos);
 		for (cmptno = 0, cmpt = dec->cmpts, compinfo = compinfos;
 		  cmptno < dec->numcomps; ++cmptno, ++cmpt, ++compinfo) {
@@ -489,7 +489,7 @@
 		dec->curtileendoff = 0;
 	}
 
-	if (JAS_CAST(int, sot->tileno) > dec->numtiles) {
+	if (JAS_CAST(int, sot->tileno) >= dec->numtiles) {
 		jas_eprintf("invalid tile number in SOT marker segment\n");
 		return -1;
 	}
@@ -692,7 +692,7 @@
 			tile->realmode = 1;
 		}
 		tcomp->numrlvls = ccp->numrlvls;
-		if (!(tcomp->rlvls = jas_malloc(tcomp->numrlvls *
+		if (!(tcomp->rlvls = jas_malloc2(tcomp->numrlvls,
 		  sizeof(jpc_dec_rlvl_t)))) {
 			return -1;
 		}
@@ -764,7 +764,7 @@
 			  rlvl->cbgheightexpn);
 
 			rlvl->numbands = (!rlvlno) ? 1 : 3;
-			if (!(rlvl->bands = jas_malloc(rlvl->numbands *
+			if (!(rlvl->bands = jas_malloc2(rlvl->numbands,
 			  sizeof(jpc_dec_band_t)))) {
 				return -1;
 			}
@@ -797,7 +797,7 @@
 
 				assert(rlvl->numprcs);
 
-				if (!(band->prcs = jas_malloc(rlvl->numprcs * sizeof(jpc_dec_prc_t)))) {
+				if (!(band->prcs = jas_malloc2(rlvl->numprcs, sizeof(jpc_dec_prc_t)))) {
 					return -1;
 				}
 
@@ -834,7 +834,7 @@
 			if (!(prc->numimsbstagtree = jpc_tagtree_create(prc->numhcblks, prc->numvcblks))) {
 				return -1;
 			}
-			if (!(prc->cblks = jas_malloc(prc->numcblks * sizeof(jpc_dec_cblk_t)))) {
+			if (!(prc->cblks = jas_malloc2(prc->numcblks, sizeof(jpc_dec_cblk_t)))) {
 				return -1;
 			}
 
@@ -1069,12 +1069,12 @@
 	/* Apply an inverse intercomponent transform if necessary. */
 	switch (tile->cp->mctid) {
 	case JPC_MCT_RCT:
-		assert(dec->numcomps == 3);
+		assert(dec->numcomps == 3 || dec->numcomps == 4);
 		jpc_irct(tile->tcomps[0].data, tile->tcomps[1].data,
 		  tile->tcomps[2].data);
 		break;
 	case JPC_MCT_ICT:
-		assert(dec->numcomps == 3);
+		assert(dec->numcomps == 3 || dec->numcomps == 4);
 		jpc_iict(tile->tcomps[0].data, tile->tcomps[1].data,
 		  tile->tcomps[2].data);
 		break;
@@ -1181,7 +1181,7 @@
 		return -1;
 	}
 
-	if (!(dec->cmpts = jas_malloc(dec->numcomps * sizeof(jpc_dec_cmpt_t)))) {
+	if (!(dec->cmpts = jas_malloc2(dec->numcomps, sizeof(jpc_dec_cmpt_t)))) {
 		return -1;
 	}
 
@@ -1204,7 +1204,7 @@
 	dec->numhtiles = JPC_CEILDIV(dec->xend - dec->tilexoff, dec->tilewidth);
 	dec->numvtiles = JPC_CEILDIV(dec->yend - dec->tileyoff, dec->tileheight);
 	dec->numtiles = dec->numhtiles * dec->numvtiles;
-	if (!(dec->tiles = jas_malloc(dec->numtiles * sizeof(jpc_dec_tile_t)))) {
+	if (!(dec->tiles = jas_calloc(dec->numtiles, sizeof(jpc_dec_tile_t)))) {
 		return -1;
 	}
 
@@ -1228,7 +1228,7 @@
 		tile->pkthdrstreampos = 0;
 		tile->pptstab = 0;
 		tile->cp = 0;
-		if (!(tile->tcomps = jas_malloc(dec->numcomps *
+		if (!(tile->tcomps = jas_calloc(dec->numcomps,
 		  sizeof(jpc_dec_tcomp_t)))) {
 			return -1;
 		}
@@ -1280,7 +1280,7 @@
 	jpc_coc_t *coc = &ms->parms.coc;
 	jpc_dec_tile_t *tile;
 
-	if (JAS_CAST(int, coc->compno) > dec->numcomps) {
+	if (JAS_CAST(int, coc->compno) >= dec->numcomps) {
 		jas_eprintf("invalid component number in COC marker segment\n");
 		return -1;
 	}
@@ -1306,7 +1306,7 @@
 	jpc_rgn_t *rgn = &ms->parms.rgn;
 	jpc_dec_tile_t *tile;
 
-	if (JAS_CAST(int, rgn->compno) > dec->numcomps) {
+	if (JAS_CAST(int, rgn->compno) >= dec->numcomps) {
 		jas_eprintf("invalid component number in RGN marker segment\n");
 		return -1;
 	}
@@ -1355,7 +1355,7 @@
 	jpc_qcc_t *qcc = &ms->parms.qcc;
 	jpc_dec_tile_t *tile;
 
-	if (JAS_CAST(int, qcc->compno) > dec->numcomps) {
+	if (JAS_CAST(int, qcc->compno) >= dec->numcomps) {
 		jas_eprintf("invalid component number in QCC marker segment\n");
 		return -1;
 	}
@@ -1489,7 +1489,7 @@
 	cp->numlyrs = 0;
 	cp->mctid = 0;
 	cp->csty = 0;
-	if (!(cp->ccps = jas_malloc(cp->numcomps * sizeof(jpc_dec_ccp_t)))) {
+	if (!(cp->ccps = jas_malloc2(cp->numcomps, sizeof(jpc_dec_ccp_t)))) {
 		return 0;
 	}
 	if (!(cp->pchglist = jpc_pchglist_create())) {
@@ -2048,7 +2048,7 @@
 	}
 	streamlist->numstreams = 0;
 	streamlist->maxstreams = 100;
-	if (!(streamlist->streams = jas_malloc(streamlist->maxstreams *
+	if (!(streamlist->streams = jas_malloc2(streamlist->maxstreams,
 	  sizeof(jas_stream_t *)))) {
 		jas_free(streamlist);
 		return 0;
@@ -2068,8 +2068,8 @@
 	/* Grow the array of streams if necessary. */
 	if (streamlist->numstreams >= streamlist->maxstreams) {
 		newmaxstreams = streamlist->maxstreams + 1024;
-		if (!(newstreams = jas_realloc(streamlist->streams,
-		  (newmaxstreams + 1024) * sizeof(jas_stream_t *)))) {
+		if (!(newstreams = jas_realloc2(streamlist->streams,
+		  (newmaxstreams + 1024), sizeof(jas_stream_t *)))) {
 			return -1;
 		}
 		for (i = streamlist->numstreams; i < streamlist->maxstreams; ++i) {
@@ -2155,8 +2155,8 @@
 {
 	jpc_ppxstabent_t **newents;
 	if (tab->maxents < maxents) {
-		newents = (tab->ents) ? jas_realloc(tab->ents, maxents *
-		  sizeof(jpc_ppxstabent_t *)) : jas_malloc(maxents * sizeof(jpc_ppxstabent_t *));
+		newents = jas_realloc2(tab->ents, maxents,
+		  sizeof(jpc_ppxstabent_t *));
 		if (!newents) {
 			return -1;
 		}
