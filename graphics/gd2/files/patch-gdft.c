--- gdft.c.orig	Thu Apr 25 14:16:21 2002
+++ gdft.c	Thu Apr 25 12:43:55 2002
@@ -513,7 +513,8 @@
 					     gdTrueColorGetRed (fg),
 					     gdTrueColorGetGreen (fg),
 					     gdTrueColorGetBlue (fg),
-	       gdAlphaMax - (gdTrueColorGetAlpha (fg) * pixel / NUMCOLORS));
+					gdAlphaMax - ((gdAlphaMax - gdTrueColorGetAlpha (fg)) * pixel / NUMCOLORS)
+			);
 	}
       else
 	{
@@ -566,76 +567,53 @@
 
       for (col = 0; col < bitmap.width; col++, pc++)
 	{
-	  if (bitmap.pixel_mode == ft_pixel_mode_grays)
-	    {
+			x = pen_x + col;
+
+			/* clip if out of bounds */
+			if (x >= im->sx || x < 0)
+				continue;
+
+			switch(bitmap.pixel_mode)	{
+				case ft_pixel_mode_grays:
 	      /*
 	       * Round to NUMCOLORS levels of antialiasing for
 	       * index color images since only 256 colors are
 	       * available.
 	       */
+
 	      tc_key.pixel = ((bitmap.buffer[pc] * NUMCOLORS)
 			      + bitmap.num_grays / 2)
 		/ (bitmap.num_grays - 1);
-	    }
-	  else if (bitmap.pixel_mode == ft_pixel_mode_mono)
-	    {
+					break;
+				case ft_pixel_mode_mono:
 	      tc_key.pixel = ((bitmap.buffer[pc / 8]
 			       << (pc % 8)) & 128) ? NUMCOLORS : 0;
-	    }
-	  else
-	    {
+					break;
+				default:
 	      return "Unsupported ft_pixel_mode";
 	    }
 
 	  if (tc_key.pixel > 0)
-	    {			/* if not background */
-	      x = pen_x + col;
-
-	      /* clip if out of bounds */
-	      if (x >= im->sx || x < 0)
-		continue;
-	      /* get pixel location in gd buffer */
-	      if (im->trueColor)
 		{
-		  tpixel = &im->tpixels[y][x];
+
+				if (im->trueColor)	{
+					tc_elem = (tweencolor_t *) gdCacheGet (
+							tc_cache, &tc_key);
+
+					gdImageSetPixel(im, x, y, tc_elem->tweencolor);
 		}
-	      else
-		{
+				else	{
 		  pixel = &im->pixels[y][x];
-		}
 	      if (tc_key.pixel == NUMCOLORS)
-		{
-		  /* use fg color directly */
-		  if (im->trueColor)
-		    {
-		      *tpixel = fg;
-		    }
-		  else
-		    {
 		      *pixel = fg;
-		    }
-		}
-	      else
-		{
-		  /* find antialised color */
-		  if (im->trueColor)
-		    {
-		      tc_key.bgcolor = *tpixel;
-		    }
-		  else
-		    {
+					else	{
 		      tc_key.bgcolor = *pixel;
-		    }
 		  tc_elem = (tweencolor_t *) gdCacheGet (
 							  tc_cache, &tc_key);
-		  if (im->trueColor)
-		    {
-		      *tpixel = tc_elem->tweencolor;
-		    }
-		  else
-		    {
 		      *pixel = tc_elem->tweencolor;
+
 		    }
+
 		}
 	    }
 	}
@@ -647,11 +625,18 @@
 
 /********************************************************************/
 /* gdImageStringFT -  render a utf8 string onto a gd image          */
-
 char *
 gdImageStringFT (gdImage * im, int *brect, int fg, char *fontlist,
 		 double ptsize, double angle, int x, int y, char *string)
 {
+	return gdImageStringFTEx(im, brect, fg, fontlist, ptsize, angle, x, y, string, NULL);
+}
+
+char *
+gdImageStringFTEx (gdImage * im, int *brect, int fg, char *fontlist,
+		 double ptsize, double angle, int x, int y, char *string,
+		 gdFTStringExtra * strex)
+{
   FT_BBox bbox, glyph_bbox;
   FT_Matrix matrix;
   FT_Vector pen, delta, penf;
@@ -672,6 +657,9 @@
   int render = (im && (im->trueColor || (fg <= 255 && fg >= -255)));
   FT_BitmapGlyph bm;
 
+	/* fine tuning */
+	double linespace = LINESPACE;
+	
 /***** initialize font library and font cache on first call ******/
   static gdCache_head_t *fontCache;
   static FT_Library library;
@@ -704,6 +692,14 @@
       return "Could not set character size";
     }
 
+	/* pull in supplied extended settings */
+	if (strex)	{
+		if (strex->flags & gdFTEX_LINESPACE == gdFTEX_LINESPACE)
+			linespace = strex->linespacing;
+
+	}
+
+	
   matrix.xx = (FT_Fixed) (cos_a * (1 << 16));
   matrix.yx = (FT_Fixed) (sin_a * (1 << 16));
   matrix.xy = -matrix.yx;
@@ -754,7 +750,7 @@
       /* newlines */
       if (ch == '\n')
 	{
-	  penf.y -= face->size->metrics.height * LINESPACE;
+			penf.y -= face->size->metrics.height * linespace;
 	  penf.y = (penf.y - 32) & -64;		/* round to next pixel row */
 	  x1 = (penf.x * cos_a - penf.y * sin_a + 32) / 64;
 	  y1 = (penf.x * sin_a + penf.y * cos_a + 32) / 64;
