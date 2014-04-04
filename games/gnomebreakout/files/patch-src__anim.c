--- ./src/anim.c.orig	2004-05-10 12:42:51.000000000 +0200
+++ ./src/anim.c	2014-04-04 17:49:31.971201127 +0200
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
