
$FreeBSD$

--- tcd/gtracked.c	2001/07/13 08:05:56	1.1
+++ tcd/gtracked.c	2001/07/13 08:06:50
@@ -211,8 +211,8 @@
     
     /* Disc area */
     g_snprintf(tmp, 63, _("Disc Information (%02u:%02u minutes)"),
-	       cd.trk[cd.last_t+1].toc.cdte_addr.msf.minute,
-	       cd.trk[cd.last_t+1].toc.cdte_addr.msf.second);
+	       TOC_MINUTE(cd.trk[cd.last_t+1]),
+	       TOC_SECOND(cd.trk[cd.last_t+1]));
 
     disc_frame = gtk_frame_new(tmp);
     disc_vbox  = gtk_vbox_new(FALSE, GNOME_PAD_SMALL);
