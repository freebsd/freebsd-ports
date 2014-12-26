--- src/png.c.orig	2011-10-27 20:56:24 UTC
+++ src/png.c
@@ -1510,7 +1510,11 @@ static int load_gif_frames(char *file_na
 	int res, val, disposal, bpp, cmask, lastzero = FALSE;
 
 
+#if GIFLIB_MAJOR >= 5
+	if (!(giffy = DGifOpenFileName(file_name, NULL))) return (-1);
+#else
 	if (!(giffy = DGifOpenFileName(file_name))) return (-1);
+#endif
 
 	/* Init state structure */
 	memset(&stat, 0, sizeof(stat));
@@ -1621,7 +1625,11 @@ static int load_gif(char *file_name, ls_
 	int delay = settings->gif_delay, trans = -1;//, disposal = 0;
 
 
+#if GIFLIB_MAJOR >= 5
+	if (!(giffy = DGifOpenFileName(file_name, NULL))) return (-1);
+#else
 	if (!(giffy = DGifOpenFileName(file_name))) return (-1);
+#endif
 
 	/* Get global palette */
 	settings->colors = convert_gif_palette(settings->pal, giffy->SColorMap);
@@ -1682,10 +1690,18 @@ static int save_gif(char *file_name, ls_
 	nc |= nc >> 1; nc |= nc >> 2; nc |= nc >> 4;
 	nc += !nc + 1; // No less than 2 colors
 
+#if GIFLIB_MAJOR >= 5
+	gif_map = GifMakeMapObject(nc, NULL);
+#else
 	gif_map = MakeMapObject(nc, NULL);
+#endif
 	if (!gif_map) return -1;
 
+#if GIFLIB_MAJOR >= 5
+	giffy = EGifOpenFileName(file_name, FALSE, NULL);
+#else
 	giffy = EGifOpenFileName(file_name, FALSE);
+#endif
 	if (!giffy) goto fail0;
 
 	for (i = 0; i < settings->colors; i++)
@@ -1732,7 +1748,11 @@ fail:	EGifCloseFile(giffy);
 	umask(mode);
 	chmod(file_name, 0666 & ~mode);
 #endif
+#if GIFLIB_MAJOR >= 5
+fail0:	GifFreeMapObject(gif_map);
+#else
 fail0:	FreeMapObject(gif_map);
+#endif
 
 	return (msg);
 }
