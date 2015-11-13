--- MF3D/mfobject.c.orig	2015-06-23 18:03:50 UTC
+++ MF3D/mfobject.c
@@ -930,7 +930,7 @@ MF3D_ObjTypeReader (
       ++inMetafilePtr->typeTable.nTypes;
       numTypes = inMetafilePtr->typeTable.nTypes;
 
-      result = MF3D_Reallocate (&inMetafilePtr->typeTable.types,
+      result = MF3D_Reallocate ((void **)&inMetafilePtr->typeTable.types,
 		       numTypes * sizeof (*inMetafilePtr->typeTable.types));
 
       if (result == kMF3DNoErr)
