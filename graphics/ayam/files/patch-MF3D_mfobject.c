--- MF3D/mfobject.c.orig	2007-09-21 13:30:36.000000000 +0200
+++ MF3D/mfobject.c	2007-12-17 19:48:57.000000000 +0100
@@ -930,7 +930,7 @@
       ++inMetafilePtr->typeTable.nTypes;
       numTypes = inMetafilePtr->typeTable.nTypes;
 
-      result = MF3D_Reallocate (&inMetafilePtr->typeTable.types,
+      result = MF3D_Reallocate ((void **)&inMetafilePtr->typeTable.types,
 		       numTypes * sizeof (*inMetafilePtr->typeTable.types));
 
       if (result == kMF3DNoErr)
