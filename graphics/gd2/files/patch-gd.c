--- gd.c.orig	Thu Apr 25 14:15:15 2002
+++ gd.c	Thu Apr 25 12:43:55 2002
@@ -1651,18 +1651,37 @@
   if (dst->trueColor)
     {
       /* 2.0: much easier when the destination is truecolor. */
+		
+		if (src->trueColor)	{
       for (y = 0; (y < h); y++)
 	{
 	  for (x = 0; (x < w); x++)
 	    {
 	      int c = gdImageGetTrueColorPixel (src, srcX + x,
 						srcY + y);
+					gdImageSetPixel (dst,
+							dstX + x,
+							dstY + y,
+							c);
+				}
+			}
+
+		}
+		else	{
+			/* source is palette based */
+			for (y = 0; (y < h); y++)
+			{
+				for (x = 0; (x < w); x++)
+				{
+					int c = gdImageGetPixel (src, srcX + x,
+							srcY + y);
 	      if (c != src->transparent)
 		{
 		  gdImageSetPixel (dst,
 				   dstX + x,
 				   dstY + y,
-				   c);
+								gdTrueColor(src->red[c], src->green[c], src->blue[c]));
+					}
 		}
 	    }
 	}
@@ -1795,18 +1814,18 @@
 	  else
 	    {
 	      dc = gdImageGetPixel (dst, tox, toy);
-	      g = 0.29900 * dst->red[dc]
-		+ 0.58700 * dst->green[dc]
-		+ 0.11400 * dst->blue[dc];
+	      g = 0.29900 * gdImageRed(dst,dc)
+		+ 0.58700 * gdImageGreen(dst,dc)
+		+ 0.11400 * gdImageBlue(dst, dc);
 
 	      ncR = gdImageRed (src, c) * (pct / 100.0)
-		+ gdImageRed (dst, dc) * g *
+		+ g *
 		((100 - pct) / 100.0);
 	      ncG = gdImageGreen (src, c) * (pct / 100.0)
-		+ gdImageGreen (dst, dc) * g *
+		+ g *
 		((100 - pct) / 100.0);
 	      ncB = gdImageBlue (src, c) * (pct / 100.0)
-		+ gdImageBlue (dst, dc) * g *
+		+ g *
 		((100 - pct) / 100.0);
 
 	      /* First look for an exact match */
@@ -2211,7 +2230,17 @@
 }
 
 void
-gdImagePolygon (gdImagePtr im, gdPointPtr p, int n, int c)
+gdImagePolygon(gdImagePtr im, gdPointPtr p, int n, int c)
+{
+	if (!n) {
+		return;
+	}
+	gdImageLine(im, p->x, p->y, p[n-1].x, p[n-1].y, c);
+	gdImageOpenPolygon(im, p, n, c);
+}	
+
+void
+gdImageOpenPolygon (gdImagePtr im, gdPointPtr p, int n, int c)
 {
   int i;
   int lx, ly;
@@ -2221,7 +2250,6 @@
     }
   lx = p->x;
   ly = p->y;
-  gdImageLine (im, lx, ly, p[n - 1].x, p[n - 1].y, c);
   for (i = 1; (i < n); i++)
     {
       p++;
@@ -2461,8 +2489,8 @@
     {
       for (x = 0; (x < sx); x++)
 	{
-	  p1 = im1->pixels[y][x];
-	  p2 = im2->pixels[y][x];
+	  p1 = im1->trueColor ? gdImageTrueColorPixel(im1, x, y) : gdImagePalettePixel(im1, x, y);
+	  p2 = im2->trueColor ? gdImageTrueColorPixel(im2, x, y) : gdImagePalettePixel(im2, x, y);
 	  if (gdImageRed (im1, p1) != gdImageRed (im2, p2))
 	    {
 	      cmpStatus |= GD_CMP_COLOR + GD_CMP_IMAGE;
