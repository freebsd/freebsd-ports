--- rw/readWriteJP2K.c.orig	2023-05-08 13:59:30 UTC
+++ rw/readWriteJP2K.c
@@ -69,7 +69,7 @@ ReadJP2K(char *file_name)
 	int i, j, k, l, w, h, w0, nc, step, delta, shift, bpp;
 	int *src, codec = CODEC_JP2;
 
-	if ((fp = fopen(file_name, "rb")) == NULL) return (-1);
+	if ((fp = fopen(file_name, "rb")) == NULL) return (Image *)(-1);
 
 	/* Read in the entire file */
 	fseek(fp, 0, SEEK_END);
