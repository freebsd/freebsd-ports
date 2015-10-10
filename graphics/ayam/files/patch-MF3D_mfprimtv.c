--- MF3D/mfprimtv.c.orig	2015-06-23 18:03:50 UTC
+++ MF3D/mfprimtv.c
@@ -1000,7 +1000,7 @@ MF3D_LabelWrite (
   if (result == kMF3DNoErr)
     {
       ++metafile->tocStuff.numReferences;
-      result = MF3D_Reallocate (&metafile->tocStuff.references,
+      result = MF3D_Reallocate ((void **)&metafile->tocStuff.references,
 				(metafile->tocStuff.numReferences *
 				 sizeof (*metafile->tocStuff.references)));
     }
