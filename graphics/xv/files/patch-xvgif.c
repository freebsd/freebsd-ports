--- src/xvgif.c.orig	2023-07-17 01:25:42 UTC
+++ src/xvgif.c
@@ -186,8 +186,12 @@ int LoadGIF(fname, pinfo)
 
   aspect = NEXTBYTE;
   if (aspect) {
+#if 0
     if (!gif89) return(gifError(pinfo,"corrupt GIF file (screen descriptor)"));
     else normaspect = (float) (aspect + 15) / 64.0;   /* gif89 aspect ratio */
+#else
+    normaspect = (float) (aspect + 15) / 64.0;   /* gif89 aspect ratio */
+#endif
     if (DEBUG) fprintf(stderr,"GIF89 aspect = %f\n", normaspect);
     /* FIXME:  apparently this _should_ apply to all frames in a multi-image
      *         GIF (i.e., PgUp/PgDn), but it doesn't */
