--- src/fe-text/gui-readline.c.orig	Mon Nov 11 15:00:02 2002
+++ src/fe-text/gui-readline.c	Sun Dec 29 19:17:27 2002
@@ -302,7 +302,7 @@
 
 	pos = gui_entry_get_pos(active_entry);
 	gui_entry_set_pos(active_entry, active_entry->text_len);
-	gui_entry_erase(active_entry, active_entry->text_len - pos, TRUE);
+	gui_entry_erase_to(active_entry, pos, TRUE);
 }
 
 static void key_yank_from_cutbuffer(void)
