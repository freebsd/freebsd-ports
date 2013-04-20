--- src/libjasper/jpc/jpc_cs.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_cs.c	2013-04-17 22:11:18.000000000 +0200
@@ -288,7 +288,7 @@
 			jpc_ms_dump(ms, stderr);
 		}
 
-		if (JAS_CAST(ulong, jas_stream_tell(tmpstream)) != ms->len) {
+		if (JAS_CAST(unsigned long, jas_stream_tell(tmpstream)) != ms->len) {
 			jas_eprintf("warning: trailing garbage in marker segment (%ld bytes)\n",
 			  ms->len - jas_stream_tell(tmpstream));
 		}
@@ -502,7 +502,7 @@
 	  !siz->tileheight || !siz->numcomps) {
 		return -1;
 	}
-	if (!(siz->comps = jas_malloc(siz->numcomps * sizeof(jpc_sizcomp_t)))) {
+	if (!(siz->comps = jas_malloc2(siz->numcomps, sizeof(jpc_sizcomp_t)))) {
 		return -1;
 	}
 	for (i = 0; i < siz->numcomps; ++i) {
@@ -744,6 +744,10 @@
 		return -1;
 	}
 	compparms->numrlvls = compparms->numdlvls + 1;
+	if (compparms->numrlvls > JPC_MAXRLVLS) {
+		jpc_cox_destroycompparms(compparms);
+		return -1;
+	}
 	if (prtflag) {
 		for (i = 0; i < compparms->numrlvls; ++i) {
 			if (jpc_getuint8(in, &tmp)) {
@@ -982,8 +986,12 @@
 		compparms->numstepsizes = (len - n) / 2;
 		break;
 	}
+	if (compparms->numstepsizes > 3 * JPC_MAXRLVLS + 1) {
+		jpc_qcx_destroycompparms(compparms);
+		return -1;
+	}
 	if (compparms->numstepsizes > 0) {
-		compparms->stepsizes = jas_malloc(compparms->numstepsizes *
+		compparms->stepsizes = jas_malloc2(compparms->numstepsizes,
 		  sizeof(uint_fast16_t));
 		assert(compparms->stepsizes);
 		for (i = 0; i < compparms->numstepsizes; ++i) {
@@ -1091,7 +1099,7 @@
 
 	ppm->len = ms->len - 1;
 	if (ppm->len > 0) {
-		if (!(ppm->data = jas_malloc(ppm->len * sizeof(unsigned char)))) {
+		if (!(ppm->data = jas_malloc2(ppm->len, sizeof(unsigned char)))) {
 			goto error;
 		}
 		if (JAS_CAST(uint, jas_stream_read(in, ppm->data, ppm->len)) != ppm->len) {
@@ -1160,7 +1168,7 @@
 	}
 	ppt->len = ms->len - 1;
 	if (ppt->len > 0) {
-		if (!(ppt->data = jas_malloc(ppt->len * sizeof(unsigned char)))) {
+		if (!(ppt->data = jas_malloc2(ppt->len, sizeof(unsigned char)))) {
 			goto error;
 		}
 		if (jas_stream_read(in, (char *) ppt->data, ppt->len) != JAS_CAST(int, ppt->len)) {
@@ -1223,7 +1231,7 @@
 	uint_fast8_t tmp;
 	poc->numpchgs = (cstate->numcomps > 256) ? (ms->len / 9) :
 	  (ms->len / 7);
-	if (!(poc->pchgs = jas_malloc(poc->numpchgs * sizeof(jpc_pocpchg_t)))) {
+	if (!(poc->pchgs = jas_malloc2(poc->numpchgs, sizeof(jpc_pocpchg_t)))) {
 		goto error;
 	}
 	for (pchgno = 0, pchg = poc->pchgs; pchgno < poc->numpchgs; ++pchgno,
@@ -1328,7 +1336,7 @@
 	jpc_crgcomp_t *comp;
 	uint_fast16_t compno;
 	crg->numcomps = cstate->numcomps;
-	if (!(crg->comps = jas_malloc(cstate->numcomps * sizeof(uint_fast16_t)))) {
+	if (!(crg->comps = jas_malloc2(cstate->numcomps, sizeof(jpc_crgcomp_t)))) {
 		return -1;
 	}
 	for (compno = 0, comp = crg->comps; compno < cstate->numcomps;
@@ -1467,7 +1475,7 @@
 	cstate = 0;
 
 	if (ms->len > 0) {
-		if (!(unk->data = jas_malloc(ms->len * sizeof(unsigned char)))) {
+		if (!(unk->data = jas_malloc2(ms->len, sizeof(unsigned char)))) {
 			return -1;
 		}
 		if (jas_stream_read(in, (char *) unk->data, ms->len) != JAS_CAST(int, ms->len)) {
