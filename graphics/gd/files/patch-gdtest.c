--- src/gdtest.c.orig	2015-09-16 11:34:29 UTC
+++ src/gdtest.c
@@ -35,6 +35,8 @@ main (int argc, char **argv)
 	gdSink imgsnk;
 	int foreground;
 	int i;
+	gdIOCtx *ctx;
+
 	if (argc != 2) {
 		fprintf(stderr, "Usage: gdtest filename.png\n");
 		exit (1);
@@ -63,6 +65,35 @@ main (int argc, char **argv)
 
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
@@ -334,6 +365,10 @@ main (int argc, char **argv)
 	printf ("[Merged Image has %d colours]\n", im2->colorsTotal);
 	CompareImages ("Merged (gdtest.png, gdtest_merge.png)", im2, im3);
 
+	out = fopen ("test/gdtest_merge_out.png", "wb");
+	gdImagePng(im2, out);
+	fclose(out);
+
 	gdImageDestroy (im2);
 	gdImageDestroy (im3);
 
