--- gif_image.C.orig	1996-07-04 20:36:15 UTC
+++ gif_image.C
@@ -58,8 +58,8 @@ GifImage::GifImage(const char *filename,
 : lockcount(0) {
 	first=0;
 	LoadGIF( filename );
-	name = strrchr(filename,'/');
-	if (name)	name=strdup(name+1);
+	const char *pos = strrchr(filename,'/');
+	if (pos)		name=strdup(pos+1);
 	else			name=strdup(filename);
 
 	if (autocrop&&!fastinfo_flag)	CropImage();
