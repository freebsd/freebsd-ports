CVE-2006-3462
===================================================================
--- libtiff/tif_next.c.orig	2008-08-17 13:03:48.978994352 -0400
+++ libtiff/tif_next.c	2008-08-17 13:03:52.894064968 -0400
@@ -105,11 +105,16 @@
 			 * as codes of the form <color><npixels>
 			 * until we've filled the scanline.
 			 */
+			/*
+			 * Ensure the run does not exceed the scanline
+			 * bounds, potentially resulting in a security issue.
+			 * -- taviso@google.com 14 Jun 2006.
+			 */
 			op = row;
 			for (;;) {
 				grey = (n>>6) & 0x3;
 				n &= 0x3f;
-				while (n-- > 0)
+				while (n-- > 0 && npixels < imagewidth)
 					SETPIXEL(op, grey);
 				if (npixels >= (int) imagewidth)
 					break;
