--- webpng.c.orig	Thu Apr 25 14:19:03 2002
+++ webpng.c	Thu Apr 25 12:43:55 2002
@@ -168,12 +168,12 @@
 	  t = gdImageGetTransparent (im);
 	  if (t != (-1))
 	    {
-	      printf ("First 100% transparent index: %d\n", t);
+				printf ("First 100%% transparent index: %d\n", t);
 	    }
 	  else
 	    {
 	      /* -1 means the image is not transparent. */
-	      printf ("First 100% transparent index: none\n");
+				printf ("First 100%% transparent index: none\n");
 	    }
 	  if (gdImageGetInterlaced (im))
 	    {
@@ -185,6 +185,40 @@
 	    }
 	  no = 0;
 	}
+		else if (!strcmp(argv[i], "-a"))
+		{
+			int maxx, maxy, x, y, alpha, pix, nalpha = 0;
+
+			maxx = gdImageSX(im);
+			maxy = gdImageSY(im);
+
+			printf("alpha channel information:\n");
+		
+			if (im->trueColor)	{
+				for (y = 0; y < maxy; y++)	{
+					for (x = 0; x < maxx; x++)	{
+						pix = gdImageGetPixel(im, x, y);
+						alpha = gdTrueColorGetAlpha(pix);
+
+						if (alpha > gdAlphaOpaque)	{
+							/* Use access macros to learn colors. */
+							printf ("%d	%d	%d	%d\n",
+									gdTrueColorGetRed(pix),
+									gdTrueColorGetGreen(pix),
+									gdTrueColorGetBlue(pix),
+									alpha);
+							nalpha++;
+						}
+
+					}
+				}
+			}
+			else
+				printf("NOT a true color image\n");
+			no = 0;	
+			printf("%d alpha channels\n", nalpha);
+			
+		}
       else
 	{
 	  fprintf (stderr, "Unknown argument: %s\n", argv[i]);
@@ -202,6 +236,7 @@
 	       "  -l         Prints the table of color indexes\n"
 	       "  -t [index] Set the transparent color to the specified index (0-255 or \"none\")\n"
 	       "  -d         Reports the dimensions and other characteristics of the image.\n"
+				"  -a         Prints all alpha channels that are not 100%% opaque.\n"
 	       "\n"
 	       "If you specify '-' as the input file, stdin/stdout will be used input/output.\n"
 	);
