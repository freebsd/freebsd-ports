Marcus Meissner noticed that there is a second instance of the BMP loader
code in imlib, nearly identical to that in io-bmp.c.
--- Imlib/load.c	2004-09-02 10:17:48.738898822 +0200
+++ Imlib/load.c	2004-09-02 10:18:32.698181227 +0200
@@ -631,12 +631,12 @@
   fread(dbuf, 4, 2, file);
   *w = (int)dbuf[0];
   *h = (int)dbuf[1];
-  if (*w > 32767)
+  if ((*w < 0) || (*w > 32767))
     {
       fprintf(stderr, "IMLIB ERROR: Image width > 32767 pixels for file\n");
       return NULL;
     }
-  if (*h > 32767)
+  if ((*h < 0) || (*h > 32767))
     {
       fprintf(stderr, "IMLIB ERROR: Image height > 32767 pixels for file\n");
       return NULL;
@@ -661,6 +661,9 @@
   ncolors = (int)dbuf[0];
   if (ncolors == 0)
     ncolors = 1 << bpp;
+  if ((ncolors < 0) || (ncolors > (1 << bpp)))
+    ncolors = 1 << bpp;
+
   /* some more sanity checks */
   if (((comp == BI_RLE4) && (bpp != 4)) || ((comp == BI_RLE8) && (bpp != 8)) || ((comp == BI_BITFIELDS) && (bpp != 16 && bpp != 32)))
     {
@@ -786,9 +789,13 @@
 		  for (bit = 0; bit < 8; bit++)
 		    {
 		      index = ((byte & (0x80 >> bit)) ? 1 : 0);
+		      /* possibly corrupted file? */
+		      if (index < ncolors && poffset < *w * *h * 3)
+			{
 		      ptr[poffset] = cmap[index].r;
 		      ptr[poffset + 1] = cmap[index].g;
 		      ptr[poffset + 2] = cmap[index].b;
+			}
 		      column++;
 		    }
 		}
@@ -810,9 +817,13 @@
 			  index = ((byte & (0xF0 >> nibble * 4)) >> (!nibble * 4));
 			  if (index >= 16)
 			    index = 15;
+			  /* possibly corrupted file? */
+			  if (index < ncolors && poffset < *w * *h * 3)
+			    {
 			  ptr[poffset] = cmap[index].r;
 			  ptr[poffset + 1] = cmap[index].g;
 			  ptr[poffset + 2] = cmap[index].b;
+			    }
 			  column++;
 			}
 		    }
@@ -851,9 +862,13 @@
 				{
 				  linepos++;
 				  byte = getc(file);
+				  /* possibly corrupted file? */
+				  if (byte < ncolors && poffset < *w * *h * 3)
+				    {
 				  ptr[poffset] = cmap[byte].r;
 				  ptr[poffset + 1] = cmap[byte].g;
 				  ptr[poffset + 2] = cmap[byte].b;
+				    }
 				  column++;
 				}
 			      if (absolute & 0x01)
@@ -864,9 +879,13 @@
 			{
 			  for (i = 0; i < first; i++)
 			    {
+			      /* possibly corrupted file? */
+			      if (byte < ncolors && poffset < *w * *h * 3)
+				{
 			      ptr[poffset] = cmap[byte].r;
 			      ptr[poffset + 1] = cmap[byte].g;
 			      ptr[poffset + 2] = cmap[byte].b;
+				}
 			      column++;
 			      linepos++;
 			    }
@@ -874,9 +893,13 @@
 		    }
 		  else
 		    {
+		      /* possibly corrupted file? */
+		      if (byte < ncolors && poffset < *w * *h * 3)
+			{
 		      ptr[poffset] = cmap[byte].r;
 		      ptr[poffset + 1] = cmap[byte].g;
 		      ptr[poffset + 2] = cmap[byte].b;
+			}
 		      column++;
 		    }
 		}
@@ -884,9 +907,12 @@
 	  else if (bpp == 24)
 	    {
 	      linepos += fread(bbuf, 1, 3, file);
+	      if (poffset< *w * *h * 3)
+		{
 	      ptr[poffset] = (unsigned char)bbuf[2];
 	      ptr[poffset + 1] = (unsigned char)bbuf[1];
 	      ptr[poffset + 2] = (unsigned char)bbuf[0];
+		}
 	      column++;
 	    }
 	  else if (bpp == 16)
@@ -894,12 +920,16 @@
 	      unsigned char       temp;
 
 	      linepos += fread(&word, 2, 1, file);
+	      /* possibly corrupted file? */
+	      if (poffset < *w * *h * 3)
+		{
 	      temp = (word & rmask) >> rshift;
 	      ptr[poffset] = temp;
 	      temp = (word & gmask) >> gshift;
 	      ptr[poffset + 1] = temp;
 	      temp = (word & bmask) >> gshift;
 	      ptr[poffset + 2] = temp;
+		}
 	      column++;
 	    }
 	  else
@@ -907,12 +937,16 @@
 	      unsigned char       temp;
 
 	      linepos += fread(&dword, 4, 1, file);
+	      /* possibly corrupted file? */
+	      if (poffset < *w * *h * 3)
+		{
 	      temp = (dword & rmask) >> rshift;
 	      ptr[poffset] = temp;
 	      temp = (dword & gmask) >> gshift;
 	      ptr[poffset + 1] = temp;
 	      temp = (dword & bmask) >> bshift;
 	      ptr[poffset + 2] = temp;
+		}
 	      column++;
 	    }
 	}
