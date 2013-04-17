--- src/libjasper/jp2/jp2_enc.c.orig	2013-04-17 22:32:23.000000000 +0200
+++ src/libjasper/jp2/jp2_enc.c	2013-04-17 22:32:23.000000000 +0200
@@ -194,7 +194,7 @@
 		}
 		bpcc = &box->data.bpcc;
 		bpcc->numcmpts = jas_image_numcmpts(image);
-		if (!(bpcc->bpcs = jas_malloc(bpcc->numcmpts *
+		if (!(bpcc->bpcs = jas_malloc2(bpcc->numcmpts,
 		  sizeof(uint_fast8_t)))) {
 			goto error;
 		}
@@ -288,7 +288,7 @@
 		}
 		cdef = &box->data.cdef;
 		cdef->numchans = jas_image_numcmpts(image);
-		cdef->ents = jas_malloc(cdef->numchans * sizeof(jp2_cdefchan_t));
+		cdef->ents = jas_malloc2(cdef->numchans, sizeof(jp2_cdefchan_t));
 		for (i = 0; i < jas_image_numcmpts(image); ++i) {
 			cdefchanent = &cdef->ents[i];
 			cdefchanent->channo = i;
