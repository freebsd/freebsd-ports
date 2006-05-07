--- image.c.orig	Sun Oct 16 21:47:00 2005
+++ image.c	Mon Jan 16 20:18:54 2006
@@ -422,6 +422,7 @@
 		buffer[i+2] = temp;
 	}
 
+	COM_CreatePath(filename);
 	if (!COM_WriteFile(filename, buffer, size + 18))
 		retval = false;
 	free (buffer);
@@ -585,17 +586,14 @@
 Image_WritePNG
 =============
 */
-int Image_WritePNG (char *filename, int compression, byte *pixels, int width, int height)
+int Image_WritePNG (char *name, int compression, byte *pixels, int width, int height)
 {
-	char		name[MAX_OSPATH];
 	int		i, bpp = 3, pngformat, width_sign;
 	FILE		*fp;
 	png_structp	png_ptr;
 	png_infop	info_ptr;
 	png_byte	**rowpointers;
 
-	Q_snprintfz (name, MAX_OSPATH, "%s/%s", com_basedir, filename);
-
 	width_sign = (width < 0) ? -1 : 1;
 	width = abs(width);
 
@@ -816,15 +814,12 @@
 Image_WriteJPEG
 =============
 */
-int Image_WriteJPEG (char *filename, int compression, byte *pixels, int width, int height)
+int Image_WriteJPEG (char *name, int compression, byte *pixels, int width, int height)
 {
-	char	name[MAX_OSPATH];
 	byte	*scanline;
 	FILE	*fout;
 	struct jpeg_compress_struct cinfo;
 	struct jpeg_error_mgr jerr;
-
-	Q_snprintfz (name, MAX_OSPATH, "%s/%s", com_basedir, filename);
 
 	if (!(fout = fopen(name, "wb")))
 	{
