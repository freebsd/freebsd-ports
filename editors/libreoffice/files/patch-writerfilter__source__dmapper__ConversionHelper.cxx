--- ./writerfilter/source/dmapper/ConversionHelper.cxx.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./writerfilter/source/dmapper/ConversionHelper.cxx	2012-04-16 14:24:48.000000000 +0200
@@ -131,7 +131,7 @@
 {
     static const sal_Int32 aBorderDefColor[] =
     {
-        COL_AUTO, COL_BLACK, COL_LIGHTBLUE, COL_LIGHTCYAN, COL_LIGHTGREEN,
+        static_cast<sal_Int32>(COL_AUTO), COL_BLACK, COL_LIGHTBLUE, COL_LIGHTCYAN, COL_LIGHTGREEN,
         COL_LIGHTMAGENTA, COL_LIGHTRED, COL_YELLOW, COL_WHITE, COL_BLUE,
         COL_CYAN, COL_GREEN, COL_MAGENTA, COL_RED, COL_BROWN, COL_GRAY,
         COL_LIGHTGRAY
