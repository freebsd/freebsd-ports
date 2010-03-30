--- image.c.orig	2005-10-16 22:47:00.000000000 +0200
+++ image.c	2010-03-30 11:54:39.000000000 +0200
@@ -422,6 +422,7 @@
 		buffer[i+2] = temp;
 	}
 
+	COM_CreatePath(filename);
 	if (!COM_WriteFile(filename, buffer, size + 18))
 		retval = false;
 	free (buffer);
@@ -533,7 +534,7 @@
 	}
 
 	if (colortype == PNG_COLOR_TYPE_GRAY && bitdepth < 8)
-		png_set_gray_1_2_4_to_8 (png_ptr);
+		png_set_expand_gray_1_2_4_to_8 (png_ptr);
 	
 	if (png_get_valid(png_ptr, pnginfo, PNG_INFO_tRNS))
 		png_set_tRNS_to_alpha (png_ptr);
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
 
@@ -816,16 +814,13 @@
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
 
-	Q_snprintfz (name, MAX_OSPATH, "%s/%s", com_basedir, filename);
-
 	if (!(fout = fopen(name, "wb")))
 	{
 		COM_CreatePath (name);
