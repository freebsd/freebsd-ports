--- src/tray.c.orig	Mon Nov 17 16:44:33 2003
+++ src/tray.c	Mon Nov 17 16:44:51 2003
@@ -117,9 +117,9 @@
 /* handle the click event on the tray icon */
 
 int tray_clicked(GtkWidget *image, GdkEventButton *event){
+	char *buf;
 	if(!insetting.update_timeout) return 1;
 	insetting.update_timeout = FALSE;
-	char *buf;
 	if(tray_icon == NULL) return 1;
 	insetting.update_timeout = TRUE; /* where done.. no need to wait */
 		check_error();
