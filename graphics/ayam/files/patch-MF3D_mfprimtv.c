--- MF3D/mfprimtv.c.orig	2016-01-13 20:09:57 UTC
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
