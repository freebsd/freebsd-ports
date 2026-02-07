--- png.c.orig	2010-03-28 13:05:30.000000000 +0200
+++ png.c	2010-03-28 13:06:28.000000000 +0200
@@ -11,7 +11,7 @@
 
 #define TITLE_KEYWORD "Title"
 
-/* check to see if a file is a png file using png_check_sig() */
+/* check to see if a file is a png file using png_sig_cmp() */
 static int check_png(char *file_name)
 {
 	ZFILE *zfp;
@@ -27,7 +27,7 @@
 	if (ret != 8)
 		return 0;
 
-	ret = png_check_sig(buf, 8);
+	ret = !png_sig_cmp(buf, 0, 8);
 
 	return (ret);
 }
