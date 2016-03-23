--- src/libjasper/base/jas_icc.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/base/jas_icc.c	2016-02-20 13:49:45.521860000 +0100
@@ -373,7 +373,7 @@
 	jas_icctagtab_t *tagtab;
 
 	tagtab = &prof->tagtab;
-	if (!(tagtab->ents = jas_malloc(prof->attrtab->numattrs *
+	if (!(tagtab->ents = jas_malloc2(prof->attrtab->numattrs,
 	  sizeof(jas_icctagtabent_t))))
 		goto error;
 	tagtab->numents = prof->attrtab->numattrs;
@@ -522,7 +522,7 @@
 	}
 	if (jas_iccgetuint32(in, &tagtab->numents))
 		goto error;
-	if (!(tagtab->ents = jas_malloc(tagtab->numents *
+	if (!(tagtab->ents = jas_malloc2(tagtab->numents,
 	  sizeof(jas_icctagtabent_t))))
 		goto error;
 	tagtabent = tagtab->ents;
@@ -743,8 +743,7 @@
 {
 	jas_iccattr_t *newattrs;
 	assert(maxents >= tab->numattrs);
-	newattrs = tab->attrs ? jas_realloc(tab->attrs, maxents *
-	  sizeof(jas_iccattr_t)) : jas_malloc(maxents * sizeof(jas_iccattr_t));
+	newattrs = jas_realloc2(tab->attrs, maxents, sizeof(jas_iccattr_t));
 	if (!newattrs)
 		return -1;
 	tab->attrs = newattrs;
@@ -999,7 +998,7 @@
 
 	if (jas_iccgetuint32(in, &curv->numents))
 		goto error;
-	if (!(curv->ents = jas_malloc(curv->numents * sizeof(jas_iccuint16_t))))
+	if (!(curv->ents = jas_malloc2(curv->numents, sizeof(jas_iccuint16_t))))
 		goto error;
 	for (i = 0; i < curv->numents; ++i) {
 		if (jas_iccgetuint16(in, &curv->ents[i]))
@@ -1011,7 +1010,6 @@
 	return 0;
 
 error:
-	jas_icccurv_destroy(attrval);
 	return -1;
 }
 
@@ -1100,7 +1098,7 @@
 	if (jas_iccgetuint32(in, &txtdesc->uclangcode) ||
 	  jas_iccgetuint32(in, &txtdesc->uclen))
 		goto error;
-	if (!(txtdesc->ucdata = jas_malloc(txtdesc->uclen * 2)))
+	if (!(txtdesc->ucdata = jas_malloc2(txtdesc->uclen, 2)))
 		goto error;
 	if (jas_stream_read(in, txtdesc->ucdata, txtdesc->uclen * 2) !=
 	  JAS_CAST(int, txtdesc->uclen * 2))
@@ -1129,7 +1127,6 @@
 #endif
 	return 0;
 error:
-	jas_icctxtdesc_destroy(attrval);
 	return -1;
 }
 
@@ -1208,8 +1205,6 @@
 		goto error;
 	return 0;
 error:
-	if (txt->string)
-		jas_free(txt->string);
 	return -1;
 }
 
@@ -1292,17 +1287,17 @@
 	  jas_iccgetuint16(in, &lut8->numouttabents))
 		goto error;
 	clutsize = jas_iccpowi(lut8->clutlen, lut8->numinchans) * lut8->numoutchans;
-	if (!(lut8->clut = jas_malloc(clutsize * sizeof(jas_iccuint8_t))) ||
-	  !(lut8->intabsbuf = jas_malloc(lut8->numinchans *
-	  lut8->numintabents * sizeof(jas_iccuint8_t))) ||
-	  !(lut8->intabs = jas_malloc(lut8->numinchans *
+	if (!(lut8->clut = jas_malloc2(clutsize, sizeof(jas_iccuint8_t))) ||
+	  !(lut8->intabsbuf = jas_malloc3(lut8->numinchans,
+	  lut8->numintabents, sizeof(jas_iccuint8_t))) ||
+	  !(lut8->intabs = jas_malloc2(lut8->numinchans,
 	  sizeof(jas_iccuint8_t *))))
 		goto error;
 	for (i = 0; i < lut8->numinchans; ++i)
 		lut8->intabs[i] = &lut8->intabsbuf[i * lut8->numintabents];
-	if (!(lut8->outtabsbuf = jas_malloc(lut8->numoutchans *
-	  lut8->numouttabents * sizeof(jas_iccuint8_t))) ||
-	  !(lut8->outtabs = jas_malloc(lut8->numoutchans *
+	if (!(lut8->outtabsbuf = jas_malloc3(lut8->numoutchans,
+	  lut8->numouttabents, sizeof(jas_iccuint8_t))) ||
+	  !(lut8->outtabs = jas_malloc2(lut8->numoutchans,
 	  sizeof(jas_iccuint8_t *))))
 		goto error;
 	for (i = 0; i < lut8->numoutchans; ++i)
@@ -1330,7 +1325,6 @@
 		goto error;
 	return 0;
 error:
-	jas_icclut8_destroy(attrval);
 	return -1;
 }
 
@@ -1461,17 +1455,17 @@
 	  jas_iccgetuint16(in, &lut16->numouttabents))
 		goto error;
 	clutsize = jas_iccpowi(lut16->clutlen, lut16->numinchans) * lut16->numoutchans;
-	if (!(lut16->clut = jas_malloc(clutsize * sizeof(jas_iccuint16_t))) ||
-	  !(lut16->intabsbuf = jas_malloc(lut16->numinchans *
-	  lut16->numintabents * sizeof(jas_iccuint16_t))) ||
-	  !(lut16->intabs = jas_malloc(lut16->numinchans *
+	if (!(lut16->clut = jas_malloc2(clutsize, sizeof(jas_iccuint16_t))) ||
+	  !(lut16->intabsbuf = jas_malloc3(lut16->numinchans,
+	  lut16->numintabents, sizeof(jas_iccuint16_t))) ||
+	  !(lut16->intabs = jas_malloc2(lut16->numinchans,
 	  sizeof(jas_iccuint16_t *))))
 		goto error;
 	for (i = 0; i < lut16->numinchans; ++i)
 		lut16->intabs[i] = &lut16->intabsbuf[i * lut16->numintabents];
-	if (!(lut16->outtabsbuf = jas_malloc(lut16->numoutchans *
-	  lut16->numouttabents * sizeof(jas_iccuint16_t))) ||
-	  !(lut16->outtabs = jas_malloc(lut16->numoutchans *
+	if (!(lut16->outtabsbuf = jas_malloc3(lut16->numoutchans,
+	  lut16->numouttabents, sizeof(jas_iccuint16_t))) ||
+	  !(lut16->outtabs = jas_malloc2(lut16->numoutchans,
 	  sizeof(jas_iccuint16_t *))))
 		goto error;
 	for (i = 0; i < lut16->numoutchans; ++i)
@@ -1499,7 +1493,6 @@
 		goto error;
 	return 0;
 error:
-	jas_icclut16_destroy(attrval);
 	return -1;
 }
 
