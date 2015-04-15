--- tools/tiffdither.c.orig	2013-05-02 14:44:29 UTC
+++ tools/tiffdither.c
@@ -39,6 +39,7 @@
 #endif
 
 #include "tiffio.h"
+#include "tiffiop.h"
 
 #define	streq(a,b)	(strcmp(a,b) == 0)
 #define	strneq(a,b,n)	(strncmp(a,b,n) == 0)
@@ -56,7 +57,7 @@ static	void usage(void);
  * Floyd-Steinberg error propragation with threshold.
  * This code is stolen from tiffmedian.
  */
-static void
+static int
 fsdither(TIFF* in, TIFF* out)
 {
 	unsigned char *outline, *inputline, *inptr;
@@ -68,14 +69,19 @@ fsdither(TIFF* in, TIFF* out)
 	int lastline, lastpixel;
 	int bit;
 	tsize_t outlinesize;
+	int errcode = 0;
 
 	imax = imagelength - 1;
 	jmax = imagewidth - 1;
 	inputline = (unsigned char *)_TIFFmalloc(TIFFScanlineSize(in));
-	thisline = (short *)_TIFFmalloc(imagewidth * sizeof (short));
-	nextline = (short *)_TIFFmalloc(imagewidth * sizeof (short));
+	thisline = (short *)_TIFFmalloc(TIFFSafeMultiply(tmsize_t, imagewidth, sizeof (short)));
+	nextline = (short *)_TIFFmalloc(TIFFSafeMultiply(tmsize_t, imagewidth, sizeof (short)));
 	outlinesize = TIFFScanlineSize(out);
 	outline = (unsigned char *) _TIFFmalloc(outlinesize);
+	if (! (inputline && thisline && nextline && outline)) {
+	    fprintf(stderr, "Out of memory.\n");
+	    goto skip_on_error;
+	}
 
 	/*
 	 * Get first line
@@ -93,7 +99,7 @@ fsdither(TIFF* in, TIFF* out)
 		nextline = tmpptr;
 		lastline = (i == imax);
 		if (TIFFReadScanline(in, inputline, i, 0) <= 0)
-			break;
+			goto skip_on_error;
 		inptr = inputline;
 		nextptr = nextline;
 		for (j = 0; j < imagewidth; ++j)
@@ -131,13 +137,18 @@ fsdither(TIFF* in, TIFF* out)
 			}
 		}
 		if (TIFFWriteScanline(out, outline, i-1, 0) < 0)
-			break;
+			goto skip_on_error;
 	}
+	goto exit_label;
+
   skip_on_error:
+	errcode = 1;
+  exit_label:
 	_TIFFfree(inputline);
 	_TIFFfree(thisline);
 	_TIFFfree(nextline);
 	_TIFFfree(outline);
+	return errcode;
 }
 
 static	uint16 compression = COMPRESSION_PACKBITS;
