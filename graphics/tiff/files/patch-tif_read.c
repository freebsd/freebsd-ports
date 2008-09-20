CVE-2006-3464,3465
===================================================================
--- libtiff/tif_read.c.orig	2008-08-17 13:03:48.990994211 -0400
+++ libtiff/tif_read.c	2008-08-17 13:03:52.898026507 -0400
@@ -31,6 +31,8 @@
 #include "tiffiop.h"
 #include <stdio.h>
 
+#include <limits.h>
+
 	int TIFFFillStrip(TIFF*, tstrip_t);
 	int TIFFFillTile(TIFF*, ttile_t);
 static	int TIFFStartStrip(TIFF*, tstrip_t);
@@ -272,7 +274,13 @@
 		if ((tif->tif_flags & TIFF_MYBUFFER) && tif->tif_rawdata)
 			_TIFFfree(tif->tif_rawdata);
 		tif->tif_flags &= ~TIFF_MYBUFFER;
-		if ( td->td_stripoffset[strip] + bytecount > tif->tif_size) {
+		/*
+		 * This sanity check could potentially overflow, causing an OOB read.
+		 * verify that offset + bytecount is > offset.
+		 * -- taviso@google.com 14 Jun 2006
+		 */
+		if ( td->td_stripoffset[strip] + bytecount > tif->tif_size ||
+			bytecount > (UINT_MAX - td->td_stripoffset[strip])) {
 			/*
 			 * This error message might seem strange, but it's
 			 * what would happen if a read were done instead.
@@ -470,7 +478,13 @@
 		if ((tif->tif_flags & TIFF_MYBUFFER) && tif->tif_rawdata)
 			_TIFFfree(tif->tif_rawdata);
 		tif->tif_flags &= ~TIFF_MYBUFFER;
-		if ( td->td_stripoffset[tile] + bytecount > tif->tif_size) {
+		/*
+		 * We must check this calculation doesnt overflow, potentially
+		 * causing an OOB read.
+		 * -- taviso@google.com 15 Jun 2006
+		 */
+		if (td->td_stripoffset[tile] + bytecount > tif->tif_size ||
+			bytecount > (UINT_MAX - td->td_stripoffset[tile])) {
 			tif->tif_curtile = NOTILE;
 			return (0);
 		}
