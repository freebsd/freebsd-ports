http://bugzilla.gnome.org/show_bug.cgi?id=151034
------- Additional Comment #5 From Dmitry V. Levin  2004-08-31 07:59 -------
diff -uprk.orig imlib-1.9.14.orig/gdk_imlib/io-bmp.c imlib-1.9.14/gdk_imlib/io-bmp.c
--- gdk_imlib/io-bmp.c	2002-03-04 20:06:29 +0300
+++ gdk_imlib/io-bmp.c	2004-08-30 13:38:02 +0400
@@ -42,12 +42,12 @@ loader_bmp (FILE *file, int *w, int *h, 
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
@@ -72,6 +72,9 @@ loader_bmp (FILE *file, int *w, int *h, 
   ncolors = (int)dbuf[0];
   if (ncolors == 0)
     ncolors = 1 << bpp;
+  if ((ncolors < 0) || (ncolors > (1 << bpp)))
+    ncolors = 1 << bpp;
+
   /* some more sanity checks */
   if (((comp == BI_RLE4) && (bpp != 4)) || ((comp == BI_RLE8) && (bpp != 8)) || ((comp == BI_BITFIELDS) && (bpp != 16 && bpp != 32)))
     {
@@ -197,9 +200,13 @@ loader_bmp (FILE *file, int *w, int *h, 
 		  for (bit = 0; bit < 8; bit++)
 		    {
 		      index = ((byte & (0x80 >> bit)) ? 1 : 0);
-		      ptr[poffset] = cmap[index].r;
-		      ptr[poffset + 1] = cmap[index].g;
-		      ptr[poffset + 2] = cmap[index].b;
+		      /* possibly corrupted file? */
+		      if (index < ncolors && poffset < *w * *h * 3)
+			{
+			  ptr[poffset] = cmap[index].r;
+			  ptr[poffset + 1] = cmap[index].g;
+			  ptr[poffset + 2] = cmap[index].b;
+			}
 		      column++;
 		    }
 		}
@@ -221,9 +228,13 @@ loader_bmp (FILE *file, int *w, int *h, 
 			  index = ((byte & (0xF0 >> nibble * 4)) >> (!nibble * 4));
 			  if (index >= 16)
 			    index = 15;
-			  ptr[poffset] = cmap[index].r;
-			  ptr[poffset + 1] = cmap[index].g;
-			  ptr[poffset + 2] = cmap[index].b;
+			  /* possibly corrupted file? */
+			  if (index < ncolors && poffset < *w * *h * 3)
+			    {
+			      ptr[poffset] = cmap[index].r;
+			      ptr[poffset + 1] = cmap[index].g;
+			      ptr[poffset + 2] = cmap[index].b;
+			    }
 			  column++;
 			}
 		    }
@@ -263,9 +274,13 @@ loader_bmp (FILE *file, int *w, int *h, 
 				{
 				  linepos++;
 				  byte = getc(file);
-				  ptr[poffset] = cmap[byte].r;
-				  ptr[poffset + 1] = cmap[byte].g;
-				  ptr[poffset + 2] = cmap[byte].b;
+				  /* possibly corrupted file? */
+				  if (byte < ncolors && poffset < *w * *h * 3)
+				    {
+				      ptr[poffset] = cmap[byte].r;
+				      ptr[poffset + 1] = cmap[byte].g;
+				      ptr[poffset + 2] = cmap[byte].b;
+				    }
 				  column++;
 				}
 			      if (absolute & 0x01)
@@ -276,9 +291,13 @@ loader_bmp (FILE *file, int *w, int *h, 
 			{
 			  for (i = 0; i < first; i++)
 			    {
-			      ptr[poffset] = cmap[byte].r;
-			      ptr[poffset + 1] = cmap[byte].g;
-			      ptr[poffset + 2] = cmap[byte].b;
+			      /* possibly corrupted file? */
+			      if (byte < ncolors && poffset < *w * *h * 3)
+				{
+				  ptr[poffset] = cmap[byte].r;
+				  ptr[poffset + 1] = cmap[byte].g;
+				  ptr[poffset + 2] = cmap[byte].b;
+				}
 			      column++;
 			      linepos++;
 			    }
@@ -286,9 +305,13 @@ loader_bmp (FILE *file, int *w, int *h, 
 		    }
 		  else
 		    {
-		      ptr[poffset] = cmap[byte].r;
-		      ptr[poffset + 1] = cmap[byte].g;
-		      ptr[poffset + 2] = cmap[byte].b;
+		      /* possibly corrupted file? */
+		      if (byte < ncolors && poffset < *w * *h * 3)
+			{
+			  ptr[poffset] = cmap[byte].r;
+			  ptr[poffset + 1] = cmap[byte].g;
+			  ptr[poffset + 2] = cmap[byte].b;
+			}
 		      column++;
 		      linepos += size;
 		    }
@@ -297,9 +320,13 @@ loader_bmp (FILE *file, int *w, int *h, 
 	  else if (bpp == 24)
 	    {
 	      linepos += fread(&bbuf, 1, 3, file);
-	      ptr[poffset] = (unsigned char)bbuf[2];
-	      ptr[poffset + 1] = (unsigned char)bbuf[1];
-	      ptr[poffset + 2] = (unsigned char)bbuf[0];
+	      /* possibly corrupted file? */
+	      if (poffset < *w * *h * 3)
+		{
+		  ptr[poffset] = (unsigned char)bbuf[2];
+		  ptr[poffset + 1] = (unsigned char)bbuf[1];
+		  ptr[poffset + 2] = (unsigned char)bbuf[0];
+		}
 	      column++;
 	    }
 	  else if (bpp == 16)
@@ -307,12 +334,16 @@ loader_bmp (FILE *file, int *w, int *h, 
 	      unsigned char       temp;
 
 	      linepos += fread(&word, 2, 1, file);
-	      temp = (word & rmask) >> rshift;
-	      ptr[poffset] = temp;
-	      temp = (word & gmask) >> gshift;
-	      ptr[poffset + 1] = temp;
-	      temp = (word & bmask) >> gshift;
-	      ptr[poffset + 2] = temp;
+	      /* possibly corrupted file? */
+	      if (poffset < *w * *h * 3)
+		{
+		  temp = (word & rmask) >> rshift;
+		  ptr[poffset] = temp;
+		  temp = (word & gmask) >> gshift;
+		  ptr[poffset + 1] = temp;
+		  temp = (word & bmask) >> gshift;
+		  ptr[poffset + 2] = temp;
+		}
 	      column++;
 	    }
 	  else
@@ -320,12 +351,16 @@ loader_bmp (FILE *file, int *w, int *h, 
 	      unsigned char       temp;
 
 	      linepos += fread(&dword, 4, 1, file);
-	      temp = (dword & rmask) >> rshift;
-	      ptr[poffset] = temp;
-	      temp = (dword & gmask) >> gshift;
-	      ptr[poffset + 1] = temp;
-	      temp = (dword & bmask) >> bshift;
-	      ptr[poffset + 2] = temp;
+	      /* possibly corrupted file? */
+	      if (poffset < *w * *h * 3)
+		{
+		  temp = (dword & rmask) >> rshift;
+		  ptr[poffset] = temp;
+		  temp = (dword & gmask) >> gshift;
+		  ptr[poffset + 1] = temp;
+		  temp = (dword & bmask) >> bshift;
+		  ptr[poffset + 2] = temp;
+		}
 	      column++;
 	    }
 	}
