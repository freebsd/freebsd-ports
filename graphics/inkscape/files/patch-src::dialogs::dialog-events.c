--- src/dialogs/dialog-events.c.orig	Thu Dec 11 08:08:58 2003
+++ src/dialogs/dialog-events.c	Thu Dec 11 08:09:47 2003
@@ -122,12 +122,13 @@
 sp_transientize_callback (Inkscape *inkscape, SPDesktop *desktop, win_data *wd)
 {
 #ifndef WIN32
+	GtkWindow *w;
+
 	if (wd->stop) { // if retransientizing of this dialog is still forbidden after previous call
 		// warning turned off because it was confusingly fired when loading many files from command line
 		//		g_warning("Retranzientize aborted! You're switching windows too fast!"); 
 		return;
 	}
-	GtkWindow *w;
 
 	w = (GtkWindow *) g_object_get_data (G_OBJECT (desktop), "window"); 
 	if (w && wd->win) {
