--- src/u_ghostscript.c.orig	2021-05-22 08:58:32 UTC
+++ src/u_ghostscript.c
@@ -805,12 +805,12 @@ display_presize(void *handle, void *device, int width,
 }
 
 static void *
-display_memalloc(void *handle, void *device, unsigned long size)
+display_memalloc(void *handle, void *device, size_t size)
 {
 	(void) device;
 	struct calldata	*data = (struct calldata *)handle;
 
-	data->img = malloc((size_t)size);
+	data->img = malloc(size);
 
 	if (appres.DEBUG && data->img == NULL)
 		fputs("gslib_bitmap() - display_memalloc(): Out of memory.\n",
