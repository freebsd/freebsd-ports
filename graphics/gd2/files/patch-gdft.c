--- gdft.c	Thu Jan 16 13:29:32 2003
+++ gdft.c	Mon Mar 24 17:09:54 2003
@@ -546,8 +546,8 @@
 	  a->tweencolor = gdTrueColorAlpha (gdTrueColorGetRed (fg),
 					    gdTrueColorGetGreen (fg),
 					    gdTrueColorGetBlue (fg),
-					    gdAlphaMax -
-					    (gdTrueColorGetAlpha (fg) *
+					    gdAlphaMax - ((gdAlphaMax -
+					    gdTrueColorGetAlpha (fg)) *
 					     pixel / NUMCOLORS));
 	}
       else
@@ -680,10 +680,14 @@
       if (y >= im->sy || y < 0)
 	continue;
 
-      for (col = 0; col < bitmap.width; col++, pc++)
-	{
-	  if (bitmap.pixel_mode == ft_pixel_mode_grays)
-	    {
+      for (col = 0; col < bitmap.width; col++, pc++) {
+	x = pen_x + col;
+	/* clip if out of bounds */
+	if (x >= im->sx || x < 0)
+	  continue;
+
+	switch(bitmap.pixel_mode) {
+	case ft_pixel_mode_grays:
 	      /*
 	       * Round to NUMCOLORS levels of antialiasing for
 	       * index color images since only 256 colors are
@@ -692,44 +696,38 @@
 	      tc_key.pixel = ((bitmap.buffer[pc] * NUMCOLORS)
 			      + bitmap.num_grays / 2)
 		/ (bitmap.num_grays - 1);
-	    }
-	  else if (bitmap.pixel_mode == ft_pixel_mode_mono)
-	    {
-	      tc_key.pixel = ((bitmap.buffer[pc / 8]
-			       << (pc % 8)) & 128) ? NUMCOLORS : 0;
+	      break;
+	case ft_pixel_mode_mono:
 	      /* 2.0.5: mode_mono fix from Giuliano Pochini */
 	      tc_key.pixel =
 		((bitmap.
 		  buffer[(col >> 3) +
 			 pcr]) & (1 << (~col & 0x07))) ? NUMCOLORS : 0;
-	    }
-	  else
-	    {
+	      break;
+	default:
 	      return "Unsupported ft_pixel_mode";
-	    }
+	}
+
 	  if (tc_key.pixel > 0)	/* if not background */
 	    {
-	      x = pen_x + col;
-
-	      /* clip if out of bounds */
-	      if (x >= im->sx || x < 0)
-		continue;
-	      /* get pixel location in gd buffer */
-	      pixel = &im->pixels[y][x];
-	      if (tc_key.pixel == NUMCOLORS)
-		{
+	      if (im->trueColor) {
+		tc_elem = (tweencolor_t *)gdCacheGet(tc_cache, &tc_key);
+		gdImageSetPixel(im, x, y, tc_elem->tweencolor);
+	      } else {
+	        /* get pixel location in gd buffer */
+	        pixel = &im->pixels[y][x];
+	        if (tc_key.pixel == NUMCOLORS)
 		  /* use fg color directly. gd 2.0.2: watch out for
 		     negative indexes (thanks to David Marwood). */
 		  *pixel = (fg < 0) ? -fg : fg;
-		}
-	      else
-		{
+	        else {
 		  /* find antialised color */
 
 		  tc_key.bgcolor = *pixel;
 		  tc_elem = (tweencolor_t *) gdCacheGet (tc_cache, &tc_key);
 		  *pixel = tc_elem->tweencolor;
 		}
+	      }
 	    }
 	}
     }
