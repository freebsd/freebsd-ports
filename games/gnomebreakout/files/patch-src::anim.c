--- src/anim.c.orig	Mon May 10 19:42:51 2004
+++ src/anim.c	Thu May 20 00:26:00 2004
@@ -47,6 +47,7 @@
 	Animation newanim;
 	char *fullfilename;
 	int i;
+	GError *gerror = NULL;
 
 	/* Find the number of frames */
 	fullfilename = g_strdup_printf("%s.%d.png", filename, 0);
@@ -64,7 +65,6 @@
 			sizeof(GdkPixbuf *));
 	for(i = 0; i < newanim.num_frames; i++) {
 		fullfilename = g_strdup_printf("%s.%d.png", filename, i);
-                GError *gerror = NULL;
 		newanim.pixmaps[i] = gdk_pixbuf_new_from_file(fullfilename,
                         &gerror);
 		if(!newanim.pixmaps[i]) {
