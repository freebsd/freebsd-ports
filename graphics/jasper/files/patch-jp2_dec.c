--- src/libjasper/jp2/jp2_dec.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/jp2/jp2_dec.c	2013-04-17 22:32:23.000000000 +0200
@@ -336,7 +336,7 @@
 	}
 
 	/* Allocate space for the channel-number to component-number LUT. */
-	if (!(dec->chantocmptlut = jas_malloc(dec->numchans * sizeof(uint_fast16_t)))) {
+	if (!(dec->chantocmptlut = jas_malloc2(dec->numchans, sizeof(uint_fast16_t)))) {
 		jas_eprintf("error: no memory\n");
 		goto error;
 	}
@@ -354,7 +354,7 @@
 			if (cmapent->map == JP2_CMAP_DIRECT) {
 				dec->chantocmptlut[channo] = channo;
 			} else if (cmapent->map == JP2_CMAP_PALETTE) {
-				lutents = jas_malloc(pclrd->numlutents * sizeof(int_fast32_t));
+				lutents = jas_malloc2(pclrd->numlutents, sizeof(int_fast32_t));
 				for (i = 0; i < pclrd->numlutents; ++i) {
 					lutents[i] = pclrd->lutdata[cmapent->pcol + i * pclrd->numchans];
 				}
