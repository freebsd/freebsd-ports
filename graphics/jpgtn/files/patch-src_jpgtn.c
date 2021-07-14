--- src/jpgtn.c.orig	2021-07-14 12:00:52 UTC
+++ src/jpgtn.c
@@ -30,6 +30,13 @@
 #include "common.h"
 #include "jpgtn.h"
 
+unsigned char *outimage;                    /* The current thumbnail image */
+unsigned char *palette;                     /* Global palette pointer      */
+int            width;                       /* Original image width        */
+int            height;                      /* Original image height       */
+int            background;                  /* Index's background color    */
+long           out_wide;                    /* Width of thumbnail image    */
+long           out_high;                    /* Height of thumbnail image   */
 
 /* Private */
 static void print_version(void);
