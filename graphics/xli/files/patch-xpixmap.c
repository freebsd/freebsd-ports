--- xpixmap.c.orig	2006-11-10 23:52:14.000000000 -0600
+++ xpixmap.c	2011-05-17 01:08:15.566413745 -0500
@@ -463,7 +463,10 @@ Image *xpixmapLoad(char *fullname, Image
 			} else
 				p = buf;
 
-			if (!xliParseXColor(&globals.dinfo, p, &xcolor)) {
+			if (!strcmp(p, "None"))
+				xliParseXColor(&globals.dinfo,
+						image_ops->bg ? image_ops->bg : "black", &xcolor);
+			else if (!xliParseXColor(&globals.dinfo, p, &xcolor)) {
 				fprintf(stderr, "xpixmapLoad: %s - Bad color name '%s'\n", name, p);
 				xcolor.red = xcolor.green = xcolor.blue = 0;
 			}
