Fix build with GTK 2.x
https://github.com/angelortega/mp-5.x/pull/40

--- mpv_gtk.c.orig	2019-02-26 08:10:09 UTC
+++ mpv_gtk.c
@@ -2533,7 +2533,7 @@ static mpdm_t gtk_drv_startup(mpdm_t a, mpdm_t ctxt)
     gtk_box_pack_start(GTK_BOX(vbox), status, FALSE, FALSE, 0);
 
 #if CONFOPT_GTK == 2
-    gtk_misc_set_alignment(GTK_MISC(label), 0, .5);
+    gtk_misc_set_alignment(GTK_MISC(status), 0, .5);
 #endif
 #if CONFOPT_GTK == 3
     gtk_label_set_xalign(GTK_LABEL(status), 0.0);
