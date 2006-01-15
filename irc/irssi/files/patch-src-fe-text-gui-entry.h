--- src/fe-text/gui-entry.h.orig	Sun Jan 15 05:08:57 2006
+++ src/fe-text/gui-entry.h	Sun Jan 15 05:09:04 2006
@@ -34,6 +34,7 @@
 
 void gui_entry_set_text(GUI_ENTRY_REC *entry, const char *str);
 char *gui_entry_get_text(GUI_ENTRY_REC *entry);
+char *gui_entry_get_text_and_pos(GUI_ENTRY_REC *entry, int *pos);
 
 void gui_entry_insert_text(GUI_ENTRY_REC *entry, const char *str);
 void gui_entry_insert_char(GUI_ENTRY_REC *entry, unichar chr);
