--- libgd/gd_gd.c.orig	2010-03-26 14:26:22.000000000 +0100
+++ libgd/gd_gd.c	2010-03-26 14:28:03.000000000 +0100
@@ -40,6 +40,9 @@
 			if (!gdGetWord(&im->colorsTotal, in)) {
 				goto fail1;
 			}
+			if (im->colorsTotal > gdMaxColors) {
+				goto fail1;
+			}
 		}
 		/* Int to accommodate truecolor single-color transparency */
 		if (!gdGetInt(&im->transparent, in)) {
