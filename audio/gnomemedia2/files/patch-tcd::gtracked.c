--- tcd/gtracked.c.orig	Mon Jun 11 13:50:57 2001
+++ tcd/gtracked.c	Tue Apr 16 15:53:53 2002
@@ -211,8 +211,8 @@
     
     /* Disc area */
     g_snprintf(tmp, 63, _("Disc Information (%02u:%02u minutes)"),
-	       cd.trk[cd.last_t+1].toc.cdte_addr.msf.minute,
-	       cd.trk[cd.last_t+1].toc.cdte_addr.msf.second);
+	       TOC_MINUTE(cd.trk[cd.last_t+1]),
+	       TOC_SECOND(cd.trk[cd.last_t+1]));
 
     disc_frame = gtk_frame_new(tmp);
     disc_vbox  = gtk_vbox_new(FALSE, GNOME_PAD_SMALL);
@@ -397,7 +397,7 @@
     
     /* build service menu */
     service_menu = gtk_menu_new();
-    key = gnome_datadir_file("gnome/cddb-submit-methods");
+    key = gnome_datadir_file("cddb-submit-methods");
     prefix = g_strconcat("=", key, "=/", NULL);
     g_free(key);
 
