--- src/menu-method.c.orig	Fri Jun 11 00:39:02 2004
+++ src/menu-method.c	Fri Jun 11 00:39:43 2004
@@ -117,7 +117,7 @@
 					    GnomeVFSOpenMode          mode,
 					    FileHandle              **handle,
 					    gboolean                  exclusive,
-					    unsigned int              perms);
+					    mode_t                    perms);
 static void           file_handle_unref    (FileHandle               *handle);
 static GnomeVFSResult file_handle_read     (FileHandle               *handle,
 					    gpointer                  buffer,
