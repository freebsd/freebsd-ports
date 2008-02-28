--- bse/bseloader-oggvorbis.c.orig	2008-02-26 23:29:43.000000000 +0100
+++ bse/bseloader-oggvorbis.c	2008-02-26 23:31:04.000000000 +0100
@@ -33,7 +33,7 @@
   BseWaveFileInfo wfi;
   OggVorbis_File  ofile;
 } FileInfo;
-#define LOADER_LOGICAL_BIT_STREAM(chunk)    ((chunk).loader_data[0].uint)
+#define LOADER_LOGICAL_BIT_STREAM(chunk)    ((chunk).loader_data[0].u_int)
 
 /* --- functions --- */
 static BseWaveFileInfo*
