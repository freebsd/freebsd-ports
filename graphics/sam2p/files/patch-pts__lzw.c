--- pts_lzw.c.orig	2002-12-12 01:43:08.000000000 +0900
+++ pts_lzw.c	2010-03-19 05:56:24.000000000 +0900
@@ -1,10 +1,3 @@
-#define DUMMY \
-set -ex; \
-g++ -DNDEBUG=1 -O3 -ansi -pedantic \
-  -Wall -W -Wstrict-prototypes -Wtraditional -Wnested-externs -Winline \
-  -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wmissing-prototypes \
-  -Wmissing-declarations pts_lzw.c -c; \
-exit
 /* pts_lzw.c -- a real, effective implementation of PostScript
  *   LanguageLevel2 and PDF /LZWEncode and /LZWDecode filters (same as the LZW
  *   compression used in TIFF raster image files)
