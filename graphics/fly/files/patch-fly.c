--- fly.c.orig	2009-06-17 01:29:36 UTC
+++ fly.c
@@ -1270,6 +1270,11 @@ void copy_to_img(FILE *infile, gdImagePt
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
