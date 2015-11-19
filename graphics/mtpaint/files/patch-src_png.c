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
@@ -1608,7 +1612,11 @@ static int load_gif_frames(char *file_na
 	}
 	res = 1;
 fail:	mem_free_chanlist(w_set.img);
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+	DGifCloseFile(giffy, NULL);
+#else
 	DGifCloseFile(giffy);
+#endif
 	return (res);
 }
 
@@ -1621,7 +1629,11 @@ static int load_gif(char *file_name, ls_
 	int delay = settings->gif_delay, trans = -1;//, disposal = 0;
 
 
+#if GIFLIB_MAJOR >= 5
+	if (!(giffy = DGifOpenFileName(file_name, NULL))) return (-1);
+#else
 	if (!(giffy = DGifOpenFileName(file_name))) return (-1);
+#endif
 
 	/* Get global palette */
 	settings->colors = convert_gif_palette(settings->pal, giffy->SColorMap);
@@ -1659,7 +1671,11 @@ static int load_gif(char *file_name, ls_
 		}
 	}
 	res = 1;
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+fail:	DGifCloseFile(giffy, NULL);
+#else
 fail:	DGifCloseFile(giffy);
+#endif
 	return (res);
 }
 
@@ -1682,10 +1698,18 @@ static int save_gif(char *file_name, ls_
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
@@ -1725,14 +1749,22 @@ static int save_gif(char *file_name, ls_
 	if (!settings->silent) progress_end();
 	msg = 0;
 
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+fail:	EGifCloseFile(giffy, NULL);
+#else
 fail:	EGifCloseFile(giffy);
+#endif
 #ifndef WIN32
 	/* giflib creates files with 0600 permissions, which is nasty - WJ */
 	mode = umask(0022);
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
