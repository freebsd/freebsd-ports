--- gd_gif_out.c~	2007-01-04 15:44:31.000000000 +0300
+++ gd_gif_out.c	2013-06-13 17:11:11.000000000 +0400
@@ -586,9 +586,9 @@
         int InitCodeSize;
         int i;
 	GifCtx ctx;
+	memset(&ctx, 0, sizeof(ctx));
         ctx.Interlace = GInterlace;
 	ctx.in_count = 1;
-	memset(&ctx, 0, sizeof(ctx));
         ColorMapSize = 1 << BitsPerPixel;
 
         RWidth = ctx.Width = GWidth;
@@ -735,9 +735,9 @@
         int InitCodeSize;
         int i;
 	GifCtx ctx;
+	memset(&ctx, 0, sizeof(ctx));
         ctx.Interlace = GInterlace;
 	ctx.in_count = 1;
-	memset(&ctx, 0, sizeof(ctx));
         ColorMapSize = 1 << BitsPerPixel;
 
 	if (LeftOfs < 0) LeftOfs = 0;
