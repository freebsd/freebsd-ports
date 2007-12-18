--- MF3D/mfprimtv.c.orig	2007-12-17 19:30:09.000000000 +0100
+++ MF3D/mfprimtv.c	2007-12-17 19:30:24.000000000 +0100
@@ -1000,7 +1000,7 @@
   if (result == kMF3DNoErr)
     {
       ++metafile->tocStuff.numReferences;
-      result = MF3D_Reallocate (&metafile->tocStuff.references,
+      result = MF3D_Reallocate ((void **)&metafile->tocStuff.references,
 				(metafile->tocStuff.numReferences *
 				 sizeof (*metafile->tocStuff.references)));
     }
