
$FreeBSD$

--- libplot/n_write.c.orig	Thu Aug  7 12:13:44 2003
+++ libplot/n_write.c	Thu Aug  7 12:39:26 2003
@@ -106,11 +106,11 @@
   int height = _plotter->b_yn;  
   FILE *fp = _plotter->data->outfp;
 #ifdef LIBPLOTTER
-  ostream *stream = _plotter->data->outstream;
+  std::ostream *outstream = _plotter->data->outstream;
 #endif
 
 #ifdef LIBPLOTTER
-  if (fp == NULL && stream == NULL)
+  if (fp == NULL && outstream == NULL)
     return;
 #else
   if (fp == NULL)
@@ -186,14 +186,14 @@
 	}
     }
 #ifdef LIBPLOTTER
-  else if (stream)
+  else if (outstream)
     {
       if (portable)			/* emit ascii format */
 	{
 	  unsigned char linebuf[MAX_PBM_PIXELS_PER_LINE];
 	  int pos = 0;		/* position in line buffer */
 
-	  (*stream) << "\
+	  (*outstream) << "\
 P1\n\
 # CREATOR: GNU libplot drawing library, version " 
 		 << PL_LIBPLOT_VER_STRING << '\n'
@@ -208,8 +208,8 @@
 		  linebuf[pos++] = '0';
 		if (pos >= MAX_PBM_PIXELS_PER_LINE || i == (width - 1))
 		  {
-		    stream->write (linebuf, pos);
-		    stream->put ('\n');
+		    outstream->write ((const char*)linebuf, pos);
+		    outstream->put ('\n');
 
 		    pos = 0;
 		  }
@@ -221,7 +221,7 @@
 	  unsigned char outbyte, set;
 	  unsigned char *rowbuf;
 
-	  (*stream) << "\
+	  (*outstream) << "\
 P4\n\
 # CREATOR: GNU libplot drawing library, version " 
 		 << PL_LIBPLOT_VER_STRING << '\n'
@@ -253,7 +253,7 @@
 		  rowbuf[bytecount++] = outbyte;
 		}
 	      /* emit row of bytes */
-	      stream->write (rowbuf, bytecount);
+	      outstream->write ((const char*)rowbuf, bytecount);
 	    }
 
 	  free (rowbuf);
@@ -278,11 +278,11 @@
   int height = _plotter->b_yn;  
   FILE *fp = _plotter->data->outfp;
 #ifdef LIBPLOTTER
-  ostream *stream = _plotter->data->outstream;
+  std::ostream *outstream = _plotter->data->outstream;
 #endif
 
 #ifdef LIBPLOTTER
-  if (fp == NULL && stream == NULL)
+  if (fp == NULL && outstream == NULL)
     return;
 #else
   if (fp == NULL)
@@ -342,7 +342,7 @@
 	}
     }
 #ifdef LIBPLOTTER
-  else if (stream)
+  else if (outstream)
     {
       if (portable)			/* emit ascii format */
 	{
@@ -351,7 +351,7 @@
 	  int pos = 0;
 	  int num_pixels = 0;
 
-	  (*stream) << "\
+	  (*outstream) << "\
 P2\n\
 # CREATOR: GNU libplot drawing library, version " 
 		 << PL_LIBPLOT_VER_STRING << '\n'
@@ -366,8 +366,8 @@
 		num_pixels++;
 		if (num_pixels >= MAX_PGM_PIXELS_PER_LINE || i == (width - 1))
 		  {
-		    stream->write (linebuf, pos);
-		    stream->put ('\n');
+		    outstream->write ((const char*)linebuf, pos);
+		    outstream->put ('\n');
 
 		    num_pixels = 0;
 		    pos = 0;
@@ -380,7 +380,7 @@
 	{
 	  unsigned char *rowbuf;
 	  
-	  (*stream) << "\
+	  (*outstream) << "\
 P5\n\
 # CREATOR: GNU libplot drawing library, version " 
 		 << PL_LIBPLOT_VER_STRING << '\n'
@@ -392,7 +392,7 @@
 	    {
 	      for (i = 0; i < width; i++)
 		rowbuf[i] = pixmap[j][i].u.rgb[0];
-	      stream->write (rowbuf, width);
+	      outstream->write ((const char*)rowbuf, width);
 	    }
 	  free (rowbuf);
 	}
@@ -416,11 +416,11 @@
   int height = _plotter->b_yn;  
   FILE *fp = _plotter->data->outfp;
 #ifdef LIBPLOTTER
-  ostream *stream = _plotter->data->outstream;
+  std::ostream *outstream = _plotter->data->outstream;
 #endif
 
 #ifdef LIBPLOTTER
-  if (fp == NULL && stream == NULL)
+  if (fp == NULL && outstream == NULL)
     return;
 #else
   if (fp == NULL)
@@ -486,7 +486,7 @@
 	}
     }
 #ifdef LIBPLOTTER
-  else if (stream)
+  else if (outstream)
     {
       if (portable)			/* emit ascii format */
 	{
@@ -495,7 +495,7 @@
 	  int pos = 0;
 	  int num_pixels = 0;
 
-	  (*stream) << "\
+	  (*outstream) << "\
 P3\n\
 # CREATOR: GNU libplot drawing library, version " 
 		 << PL_LIBPLOT_VER_STRING << '\n'
@@ -514,8 +514,8 @@
 		num_pixels++;
 		if (num_pixels >= MAX_PPM_PIXELS_PER_LINE || i == (width - 1))
 		  {
-		    stream->write (linebuf, pos);
-		    stream->put ('\n');
+		    outstream->write ((const char*)linebuf, pos);
+		    outstream->put ('\n');
 
 		    num_pixels = 0;
 		    pos = 0;
@@ -529,7 +529,7 @@
 	  unsigned char *rowbuf;
 	  int component;
 	  
-	  (*stream) << "\
+	  (*outstream) << "\
 P6\n\
 # CREATOR: GNU libplot drawing library, version " 
 		 << PL_LIBPLOT_VER_STRING << '\n'
@@ -542,7 +542,7 @@
 	      for (i = 0; i < width; i++)
 		for (component = 0; component < 3; component++)
 		  rowbuf[3 * i + component] = pixmap[j][i].u.rgb[component];
-	      stream->write (rowbuf, 3 * width);
+	      outstream->write ((const char*)rowbuf, 3 * width);
 	    }
 	  free (rowbuf);
 	}
