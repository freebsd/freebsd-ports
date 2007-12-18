--- MF3D/mffile.c.orig	2007-12-17 19:24:47.000000000 +0100
+++ MF3D/mffile.c	2007-12-17 19:25:03.000000000 +0100
@@ -102,7 +102,7 @@
       /* Add this type to the table */
       ++inMetafilePtr->typeTable.nTypes;
       numTypes = inMetafilePtr->typeTable.nTypes;
-      result = MF3D_Reallocate (&inMetafilePtr->typeTable.types,
+      result = MF3D_Reallocate ((void **)&inMetafilePtr->typeTable.types,
 		       numTypes * sizeof (*inMetafilePtr->typeTable.types));
       if (result == kMF3DNoErr)
 	{
