--- src/fe-text/gui-entry.c.orig	Sun Oct 26 13:45:02 2003
+++ src/fe-text/gui-entry.c	Sun Dec  7 16:33:14 2003
@@ -226,7 +226,7 @@
 	}
 }
 
-void gui_entry_set_prompt(GUI_ENTRY_REC *entry, const char *str)
+void gui_entry_set_prompt(GUI_ENTRY_REC *entry, const unsigned char *str)
 {
 	int oldlen;
 
@@ -262,7 +262,7 @@
         entry->utf8 = utf8;
 }
 
-void gui_entry_set_text(GUI_ENTRY_REC *entry, const char *str)
+void gui_entry_set_text(GUI_ENTRY_REC *entry, const unsigned char *str)
 {
 	g_return_if_fail(entry != NULL);
 	g_return_if_fail(str != NULL);
@@ -291,7 +291,7 @@
 	return buf;
 }
 
-void gui_entry_insert_text(GUI_ENTRY_REC *entry, const char *str)
+void gui_entry_insert_text(GUI_ENTRY_REC *entry, const unsigned char *str)
 {
         unichar chr;
 	int i, len;
