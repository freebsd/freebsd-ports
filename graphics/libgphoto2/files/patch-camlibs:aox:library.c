--- camlibs/aox/library.c.orig	Mon Jan 26 01:22:59 2004
+++ camlibs/aox/library.c	Mon Jan 26 01:23:58 2004
@@ -167,7 +167,7 @@
 	unsigned char *data;
 	unsigned char *p_data = NULL;
 	unsigned char *output = NULL;     
-	int len;
+	int len, header_len;
 	char header[128];	
 	unsigned char gtable[256];
 
@@ -222,7 +222,7 @@
 			GP_DEBUG("size of data = %i\n", sizeof(data));
 			GP_DEBUG("size of p_data = %i\n", sizeof(p_data));
 			/* And now create a ppm file, with our own header */
-			int  header_len = snprintf(header, 127, 
+			header_len = snprintf(header, 127, 
 				"P6\n" 
 				"# CREATOR: gphoto2, aox library\n" 
 				"%d %d\n" 
