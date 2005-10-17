--- fly.c.orig	Sun Nov 25 19:39:28 2001
+++ fly.c	Mon Oct 17 23:48:51 2005
@@ -1270,6 +1270,11 @@
 	} else {
 		img_file = gdImageCreateFromPng(img_to_copy);
 	}
+	if (img_file == NULL) {
+		fprintf(stderr, "Error: Cannot read image file \"%s\" of type \"%s\"\n",
+			filename, imgtype == GIF ? "gif" : (imgtype == JPEG ? "jpeg" : "png"));
+		exit(1);
+	}
 	fclose(img_to_copy);
 
 	if( resize == 1 )
