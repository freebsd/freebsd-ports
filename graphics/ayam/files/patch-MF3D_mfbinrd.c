--- MF3D/mfbinrd.c.orig	2007-12-17 19:17:47.000000000 +0100
+++ MF3D/mfbinrd.c	2007-12-17 19:23:12.000000000 +0100
@@ -132,7 +132,7 @@
 	  MFASSERT (!MF3DIsTextFormat (tocPtr->nextTOC->format));
 	  AssignInt64 (nextTocLoc, tocPtr->nextTOC->location.binary);
 	  numNewRefs = tocPtr->nEntries;
-	  result = MF3D_Reallocate (&inMetafilePtr->tocStuff.references,
+	  result = MF3D_Reallocate ((void **) &inMetafilePtr->tocStuff.references,
 				    ((numReferences + numNewRefs) *
 			     sizeof (*inMetafilePtr->tocStuff.references)));
 	  if (result != kMF3DNoErr)
