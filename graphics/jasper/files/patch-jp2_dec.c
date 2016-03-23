--- src/libjasper/jp2/jp2_dec.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/jp2/jp2_dec.c	2016-02-20 13:49:45.565514000 +0100
@@ -291,7 +291,10 @@
 	case JP2_COLR_ICC:
 		iccprof = jas_iccprof_createfrombuf(dec->colr->data.colr.iccp,
 		  dec->colr->data.colr.iccplen);
-		assert(iccprof);
+		if (!iccprof) {
+			jas_eprintf("error: failed to parse ICC profile\n");
+			goto error;
+		}
 		jas_iccprof_gethdr(iccprof, &icchdr);
 		jas_eprintf("ICC Profile CS %08x\n", icchdr.colorspc);
 		jas_image_setclrspc(dec->image, fromiccpcs(icchdr.colorspc));
@@ -336,7 +339,7 @@
 	}
 
 	/* Allocate space for the channel-number to component-number LUT. */
-	if (!(dec->chantocmptlut = jas_malloc(dec->numchans * sizeof(uint_fast16_t)))) {
+	if (!(dec->chantocmptlut = jas_malloc2(dec->numchans, sizeof(uint_fast16_t)))) {
 		jas_eprintf("error: no memory\n");
 		goto error;
 	}
@@ -354,7 +357,7 @@
 			if (cmapent->map == JP2_CMAP_DIRECT) {
 				dec->chantocmptlut[channo] = channo;
 			} else if (cmapent->map == JP2_CMAP_PALETTE) {
-				lutents = jas_malloc(pclrd->numlutents * sizeof(int_fast32_t));
+				lutents = jas_malloc2(pclrd->numlutents, sizeof(int_fast32_t));
 				for (i = 0; i < pclrd->numlutents; ++i) {
 					lutents[i] = pclrd->lutdata[cmapent->pcol + i * pclrd->numchans];
 				}
@@ -386,6 +389,11 @@
 	/* Determine the type of each component. */
 	if (dec->cdef) {
 		for (i = 0; i < dec->numchans; ++i) {
+			/* Is the channel number reasonable? */
+			if (dec->cdef->data.cdef.ents[i].channo >= dec->numchans) {
+				jas_eprintf("error: invalid channel number in CDEF box\n");
+				goto error;
+			}
 			jas_image_setcmpttype(dec->image,
 			  dec->chantocmptlut[dec->cdef->data.cdef.ents[i].channo],
 			  jp2_getct(jas_image_clrspc(dec->image),
