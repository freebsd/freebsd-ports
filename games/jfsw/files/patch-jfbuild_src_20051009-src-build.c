--- jfbuild_src_20051009/src/build.c.orig	2005-10-09 15:23:00.000000000 +0200
+++ jfbuild_src_20051009/src/build.c	2005-10-10 15:06:18.000000000 +0200
@@ -86,7 +86,7 @@
 
 short temppicnum, tempcstat, templotag, temphitag, tempextra;
 char tempshade, temppal, tempvis, tempxrepeat, tempyrepeat;
-char somethingintab = 255;
+static char somethingintab = 255;
 
 static char boardfilename[BMAX_PATH], selectedboardfilename[BMAX_PATH];
 static struct _directoryitem {
