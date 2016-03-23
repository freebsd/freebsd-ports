--- src/libjasper/jp2/jp2_cod.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/jp2/jp2_cod.c	2016-02-20 13:49:45.560559000 +0100
@@ -247,7 +247,7 @@
 	box = 0;
 	tmpstream = 0;
 
-	if (!(box = jas_malloc(sizeof(jp2_box_t)))) {
+	if (!(box = jas_calloc(1, sizeof(jp2_box_t)))) {
 		goto error;
 	}
 	box->ops = &jp2_boxinfo_unk.ops;
@@ -372,7 +372,7 @@
 	jp2_bpcc_t *bpcc = &box->data.bpcc;
 	unsigned int i;
 	bpcc->numcmpts = box->datalen;
-	if (!(bpcc->bpcs = jas_malloc(bpcc->numcmpts * sizeof(uint_fast8_t)))) {
+	if (!(bpcc->bpcs = jas_malloc2(bpcc->numcmpts, sizeof(uint_fast8_t)))) {
 		return -1;
 	}
 	for (i = 0; i < bpcc->numcmpts; ++i) {
@@ -416,7 +416,7 @@
 		break;
 	case JP2_COLR_ICC:
 		colr->iccplen = box->datalen - 3;
-		if (!(colr->iccp = jas_malloc(colr->iccplen * sizeof(uint_fast8_t)))) {
+		if (!(colr->iccp = jas_malloc2(colr->iccplen, sizeof(uint_fast8_t)))) {
 			return -1;
 		}
 		if (jas_stream_read(in, colr->iccp, colr->iccplen) != colr->iccplen) {
@@ -453,7 +453,7 @@
 	if (jp2_getuint16(in, &cdef->numchans)) {
 		return -1;
 	}
-	if (!(cdef->ents = jas_malloc(cdef->numchans * sizeof(jp2_cdefchan_t)))) {
+	if (!(cdef->ents = jas_malloc2(cdef->numchans, sizeof(jp2_cdefchan_t)))) {
 		return -1;
 	}
 	for (channo = 0; channo < cdef->numchans; ++channo) {
@@ -766,7 +766,7 @@
 	unsigned int i;
 
 	cmap->numchans = (box->datalen) / 4;
-	if (!(cmap->ents = jas_malloc(cmap->numchans * sizeof(jp2_cmapent_t)))) {
+	if (!(cmap->ents = jas_malloc2(cmap->numchans, sizeof(jp2_cmapent_t)))) {
 		return -1;
 	}
 	for (i = 0; i < cmap->numchans; ++i) {
@@ -828,10 +828,10 @@
 		return -1;
 	}
 	lutsize = pclr->numlutents * pclr->numchans;
-	if (!(pclr->lutdata = jas_malloc(lutsize * sizeof(int_fast32_t)))) {
+	if (!(pclr->lutdata = jas_malloc2(lutsize, sizeof(int_fast32_t)))) {
 		return -1;
 	}
-	if (!(pclr->bpc = jas_malloc(pclr->numchans * sizeof(uint_fast8_t)))) {
+	if (!(pclr->bpc = jas_malloc2(pclr->numchans, sizeof(uint_fast8_t)))) {
 		return -1;
 	}
 	for (i = 0; i < pclr->numchans; ++i) {
