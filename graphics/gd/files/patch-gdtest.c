--- gdtest.c.orig	Sat Feb  3 02:41:00 2007
+++ gdtest.c	Sat Feb 17 14:09:35 2007
@@ -36,6 +36,8 @@
   gdSink imgsnk;
   int foreground;
   int i;
+  gdIOCtx *ctx;
+
   if (argc != 2)
     {
       fprintf (stderr, "Usage: gdtest filename.png\n");
@@ -58,6 +60,35 @@
 
   CompareImages ("Initial Versions", ref, im);
 
+        /* */
+        /* Send to GIF File then Ptr */
+        /* */
+        sprintf(of, "%s.gif", argv[1]);
+        out = fopen(of, "wb");
+        gdImageGif(im, out);
+        fclose(out);
+
+        in = fopen(of, "rb");
+        if (!in) {
+                fprintf(stderr, "GIF Output file does not exist!\n");
+                exit(1);
+        }
+        im2 = gdImageCreateFromGif(in);
+        fclose(in);
+
+        CompareImages("GD->GIF File->GD", ref, im2);
+
+        unlink(of);
+        gdImageDestroy(im2);
+
+	iptr = gdImageGifPtr(im,&sz);
+	ctx = gdNewDynamicCtx(sz,iptr);
+	im2 = gdImageCreateFromGifCtx(ctx);
+
+        CompareImages("GD->GIF ptr->GD", ref, im2);
+
+	gdImageDestroy(im2);
+	ctx->gd_free(ctx);
 
   /* */
   /* Send to PNG File then Ptr */
@@ -268,6 +299,10 @@
 
   printf ("[Merged Image has %d colours]\n", im2->colorsTotal);
   CompareImages ("Merged (gdtest.png, gdtest_merge.png)", im2, im3);
+
+  out = fopen ("test/gdtest_merge_out.png", "wb");
+  gdImagePng(im2, out);
+  fclose(out);
 
   gdImageDestroy (im2);
   gdImageDestroy (im3);
