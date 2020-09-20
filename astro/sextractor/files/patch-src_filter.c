--- src/filter.c.orig	2005-12-21 19:26:40 UTC
+++ src/filter.c
@@ -32,6 +32,8 @@
 #include	"filter.h"
 #include	"image.h"
 
+filterstruct	*thefilter;
+
 /******************************** convolve ***********************************/
 /*
 Convolve a scan line with an array.
