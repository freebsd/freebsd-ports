--- MF3D/mffile.c.orig	2016-01-13 20:09:57 UTC
+++ MF3D/mffile.c
@@ -102,7 +102,7 @@ MF3D_TypeObjWrite (
       /* Add this type to the table */
       ++inMetafilePtr->typeTable.nTypes;
       numTypes = inMetafilePtr->typeTable.nTypes;
-      result = MF3D_Reallocate (&inMetafilePtr->typeTable.types,
+      result = MF3D_Reallocate ((void **)&inMetafilePtr->typeTable.types,
 		       numTypes * sizeof (*inMetafilePtr->typeTable.types));
       if (result == kMF3DNoErr)
 	{
