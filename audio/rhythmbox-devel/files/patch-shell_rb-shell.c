--- shell/rb-shell.c.orig	Thu Jan 22 03:35:39 2004
+++ shell/rb-shell.c	Thu Jan 22 03:36:04 2004
@@ -610,10 +610,10 @@
 {
 	RBShell *shell = RB_SHELL (bonobo_object (_servant));
 	RBPlaylist *parser;
+	GnomeVFSURI *vfsuri = gnome_vfs_uri_new (uri);
 
 	rb_debug ("handling uri: %s", uri);
 
-	GnomeVFSURI *vfsuri = gnome_vfs_uri_new (uri);
 	if (!vfsuri) {
 		rb_error_dialog (_("Unable to parse URI \"%s\"\n"), uri);
 		return;
