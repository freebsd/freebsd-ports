--- src/libjasper/jpc/jpc_dec.c	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_dec.c	2011-11-09 15:04:49.000000000 +0100
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
