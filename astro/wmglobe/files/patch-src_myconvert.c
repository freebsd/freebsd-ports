--- src/myconvert.c.orig	2020-09-16 20:04:28 UTC
+++ src/myconvert.c
@@ -253,7 +253,7 @@ static RXImage *image2PseudoColor(RContext * ctx, RIma
     const unsigned short bmask = rmask;
     unsigned short *rtable, *gtable, *btable;
     const int cpccpc = cpc * cpc;
-    unsigned char *data;
+    char *data;
     int ofs;
     /*register unsigned char maxrgb = 0xff; */
 
@@ -420,7 +420,7 @@ static RXImage *image2GrayScale(RContext * ctx, RImage
     const int cpc = ctx->attribs->colors_per_channel;
     unsigned short gmask;
     unsigned short *table;
-    unsigned char *data;
+    char *data;
     int ofs;
     /*register unsigned char maxrgb = 0xff; */
 
