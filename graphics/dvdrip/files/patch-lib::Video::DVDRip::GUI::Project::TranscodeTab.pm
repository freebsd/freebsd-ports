--- lib/Video/DVDRip/GUI/Project/TranscodeTab.pm.orig	Fri Dec 20 12:15:47 2002
+++ lib/Video/DVDRip/GUI/Project/TranscodeTab.pm	Fri Dec 20 12:16:11 2002
@@ -218,7 +218,7 @@
 
 	$entry = Gtk::Combo->new;
 	$entry->show;
-	$entry->set_popdown_strings ("SVCD","VCD","divx4","divx5","xvid","xvidcvs","ffmpeg","fame","af6");
+	$entry->set_popdown_strings ("SVCD","VCD","xvid","ffmpeg","fame","af6");
 	$entry->set_usize(80,undef);
 	$hbox->pack_start($entry, 0, 1, 0);
 
