--- gdtest.c.orig	Thu Apr 25 14:16:47 2002
+++ gdtest.c	Tue Nov  6 15:53:38 2001
@@ -84,6 +84,35 @@
   gdImageDestroy (im2);
   ctx->gd_free (ctx);
 
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
   /* Send to GD2 File then Ptr */
@@ -200,7 +229,30 @@
       gdImageDestroy (im2);
     };
 
-  unlink (of);
+	/*
+	** Test gdImageCreateFromGifSource
+	**/
+
+	in = fopen(of, "rb");
+
+	if (!in)
+	  {
+		fprintf (stderr, "GD Source: ERROR - GD Source input file does not exist - Sink may have failed!\n");
+	  };
+
+	imgsrc.source = freadWrapper;
+	imgsrc.context = in;
+	im2 = gdImageCreateFromGifSource(&imgsrc);
+	fclose(in);
+
+	if (im2 == NULL) {
+		printf("GD Source (GIF): ERROR Null returned by gdImageCreateFromGifSource\n");
+	} else {
+		CompareImages("GD Source (GIF)", ref, im2);
+		gdImageDestroy(im2);
+	};
+
+	unlink(of);
 
   /* */
   /*  Test Extraction */
@@ -266,6 +318,10 @@
 
   printf ("[Merged Image has %d colours]\n", im2->colorsTotal);
   CompareImages ("Merged (gdtest.png, gdtest_merge.png)", im2, im3);
+
+  out = fopen ("test/gdtest_merge_out.png", "wb");
+  gdImagePng(im2, out);
+  close(out);
 
   gdImageDestroy (im2);
   gdImageDestroy (im3);
