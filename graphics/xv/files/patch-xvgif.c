--- xvgif.c.orig	2009-05-17 08:25:07.000000000 +0200
+++ xvgif.c	2009-05-17 09:37:28.000000000 +0200
@@ -169,8 +169,12 @@
  
   aspect = NEXTBYTE;
   if (aspect) {
+#if 0
     if (!gif89) return(gifError(pinfo,"corrupt GIF file (screen descriptor)"));
     else normaspect = (float) (aspect + 15) / 64.0;   /* gif89 aspect ratio */
+#else
+    normaspect = (float) (aspect + 15) / 64.0;   /* gif89 aspect ratio */
+#endif
     if (DEBUG) fprintf(stderr,"GIF89 aspect = %f\n", normaspect);
   }
 
