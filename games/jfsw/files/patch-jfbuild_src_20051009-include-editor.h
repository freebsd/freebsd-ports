--- jfbuild_src_20051009/include/editor.h.orig	2005-10-09 15:23:02.000000000 +0200
+++ jfbuild_src_20051009/include/editor.h	2005-10-10 15:06:18.000000000 +0200
@@ -18,7 +18,7 @@
 
 extern short temppicnum, tempcstat, templotag, temphitag, tempextra;
 extern char tempshade, temppal, tempxrepeat, tempyrepeat;
-extern char somethingintab;
+static char somethingintab;
 
 extern char buildkeys[NUMBUILDKEYS];
 
