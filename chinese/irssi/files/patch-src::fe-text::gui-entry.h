--- src/fe-text/gui-entry.h.orig	Wed Feb 20 20:46:45 2002
+++ src/fe-text/gui-entry.h	Sun Dec 29 19:19:26 2002
@@ -28,17 +28,18 @@
 void gui_entry_move(GUI_ENTRY_REC *entry, int xpos, int ypos, int width);
 void gui_entry_set_active(GUI_ENTRY_REC *entry);
 
-void gui_entry_set_prompt(GUI_ENTRY_REC *entry, const char *str);
+void gui_entry_set_prompt(GUI_ENTRY_REC *entry, const unsigned char *str);
 void gui_entry_set_hidden(GUI_ENTRY_REC *entry, int hidden);
 void gui_entry_set_utf8(GUI_ENTRY_REC *entry, int utf8);
 
-void gui_entry_set_text(GUI_ENTRY_REC *entry, const char *str);
+void gui_entry_set_text(GUI_ENTRY_REC *entry, const unsigned char *str);
 char *gui_entry_get_text(GUI_ENTRY_REC *entry);
 
-void gui_entry_insert_text(GUI_ENTRY_REC *entry, const char *str);
+void gui_entry_insert_text(GUI_ENTRY_REC *entry, const unsigned char *str);
 void gui_entry_insert_char(GUI_ENTRY_REC *entry, unichar chr);
 
 char *gui_entry_get_cutbuffer(GUI_ENTRY_REC *entry);
+void gui_entry_erase_to(GUI_ENTRY_REC *entry, int pos, int update_cutbuffer);
 void gui_entry_erase(GUI_ENTRY_REC *entry, int size, int update_cutbuffer);
 void gui_entry_erase_word(GUI_ENTRY_REC *entry, int to_space);
 void gui_entry_erase_next_word(GUI_ENTRY_REC *entry, int to_space);
