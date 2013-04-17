--- src/libjasper/base/jas_cm.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/base/jas_cm.c	2013-04-17 22:32:23.000000000 +0200
@@ -704,8 +704,7 @@
 {
 	jas_cmpxform_t **p;
 	assert(n >= pxformseq->numpxforms);
-	p = (!pxformseq->pxforms) ? jas_malloc(n * sizeof(jas_cmpxform_t *)) :
-	  jas_realloc(pxformseq->pxforms, n * sizeof(jas_cmpxform_t *));
+	p = jas_realloc2(pxformseq->pxforms, n, sizeof(jas_cmpxform_t *));
 	if (!p) {
 		return -1;
 	}
@@ -889,13 +888,13 @@
 	jas_cmshapmatlut_cleanup(lut);
 	if (curv->numents == 0) {
 		lut->size = 2;
-		if (!(lut->data = jas_malloc(lut->size * sizeof(jas_cmreal_t))))
+		if (!(lut->data = jas_malloc2(lut->size, sizeof(jas_cmreal_t))))
 			goto error;
 		lut->data[0] = 0.0;
 		lut->data[1] = 1.0;
 	} else if (curv->numents == 1) {
 		lut->size = 256;
-		if (!(lut->data = jas_malloc(lut->size * sizeof(jas_cmreal_t))))
+		if (!(lut->data = jas_malloc2(lut->size, sizeof(jas_cmreal_t))))
 			goto error;
 		gamma = curv->ents[0] / 256.0;
 		for (i = 0; i < lut->size; ++i) {
@@ -903,7 +902,7 @@
 		}
 	} else {
 		lut->size = curv->numents;
-		if (!(lut->data = jas_malloc(lut->size * sizeof(jas_cmreal_t))))
+		if (!(lut->data = jas_malloc2(lut->size, sizeof(jas_cmreal_t))))
 			goto error;
 		for (i = 0; i < lut->size; ++i) {
 			lut->data[i] = curv->ents[i] / 65535.0;
@@ -953,7 +952,7 @@
 			return -1;
 		}
 	}
-	if (!(invlut->data = jas_malloc(n * sizeof(jas_cmreal_t))))
+	if (!(invlut->data = jas_malloc2(n, sizeof(jas_cmreal_t))))
 		return -1;
 	invlut->size = n;
 	for (i = 0; i < invlut->size; ++i) {
