--- src/jpgtn.h.orig	2021-07-14 12:00:47 UTC
+++ src/jpgtn.h
@@ -36,13 +36,13 @@
 #define RSZ_WIDTH  1
 #define RSZ_HEIGHT 2
 
-unsigned char *outimage;                    /* The current thumbnail image */
-unsigned char *palette;                     /* Global palette pointer      */
-int            width;                       /* Original image width        */
-int            height;                      /* Original image height       */
-int            background;                  /* Index's background color    */
-long           out_wide;                    /* Width of thumbnail image    */
-long           out_high;                    /* Height of thumbnail image   */
+extern unsigned char *outimage;                    /* The current thumbnail image */
+extern unsigned char *palette;                     /* Global palette pointer      */
+extern int            width;                       /* Original image width        */
+extern int            height;                      /* Original image height       */
+extern int            background;                  /* Index's background color    */
+extern long           out_wide;                    /* Width of thumbnail image    */
+extern long           out_high;                    /* Height of thumbnail image   */
 
 
 /* resizepic.c */
