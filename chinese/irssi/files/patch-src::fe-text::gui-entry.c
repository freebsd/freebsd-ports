--- src/fe-text/gui-entry.c.orig	Tue Oct 15 02:45:08 2002
+++ src/fe-text/gui-entry.c	Sun Dec 29 19:18:05 2002
@@ -68,6 +68,27 @@
         g_free(entry);
 }
 
+/* Fixes the cursor position if it at big5_lo .
+   Direct: -1    ,  left shift 1 byte.
+   Direct: 0, +1 ,  right shift 1 byte.
+*/
+static int _fix_big5_pos(unichar *p, int pos, int direct)
+{
+	int newpos;
+
+	for (newpos=0; newpos<pos && p[newpos] != 0; ) {
+		if (is_big5(p[newpos], p[newpos+1]))
+			newpos += 2;
+		else
+			newpos ++;
+	}
+
+	if (newpos != pos)
+		pos += direct > 0 ? 1 : -1;
+
+	return pos;
+}
+
 /* Fixes the cursor position in screen */
 static void gui_entry_fix_cursor(GUI_ENTRY_REC *entry)
 {
@@ -85,6 +106,8 @@
 		entry->scrstart = entry->pos - entry->scrpos;
 	}
 
+	entry->scrstart = _fix_big5_pos(entry->text, entry->scrstart, -1);
+
 	if (old_scrstart != entry->scrstart)
                 entry->redraw_needed_from = 0;
 }
@@ -200,7 +223,7 @@
 	}
 }
 
-void gui_entry_set_prompt(GUI_ENTRY_REC *entry, const char *str)
+void gui_entry_set_prompt(GUI_ENTRY_REC *entry, const unsigned char *str)
 {
 	int oldlen;
 
@@ -236,7 +259,7 @@
         entry->utf8 = utf8;
 }
 
-void gui_entry_set_text(GUI_ENTRY_REC *entry, const char *str)
+void gui_entry_set_text(GUI_ENTRY_REC *entry, const unsigned char *str)
 {
 	g_return_if_fail(entry != NULL);
 	g_return_if_fail(str != NULL);
@@ -265,7 +288,7 @@
 	return buf;
 }
 
-void gui_entry_insert_text(GUI_ENTRY_REC *entry, const char *str)
+void gui_entry_insert_text(GUI_ENTRY_REC *entry, const unsigned char *str)
 {
         unichar chr;
 	int i, len;
@@ -341,13 +364,30 @@
 	return buf;
 }
 
+void gui_entry_erase_to(GUI_ENTRY_REC *entry, int pos, int update_cutbuffer)
+{
+  int newpos, size = 0;
+  
+  g_return_if_fail(entry != NULL);
+  for(newpos = gui_entry_get_pos(entry); newpos > pos; size ++)
+    newpos = _fix_big5_pos(entry->text, newpos - 1, -1);
+  gui_entry_erase(entry, size, update_cutbuffer);
+}
+
 void gui_entry_erase(GUI_ENTRY_REC *entry, int size, int update_cutbuffer)
 {
+	int newpos;
+
         g_return_if_fail(entry != NULL);
 
 	if (entry->pos < size)
 		return;
 
+	/* recount the erase size with big5 charsets */
+	for (newpos = entry->pos; newpos > 0 && size > 0; size--)
+		newpos = _fix_big5_pos(entry->text, newpos-1, -1);
+	size = entry->pos - newpos;
+
 	if (update_cutbuffer) {
 		/* put erased text to cutbuffer */
 		if (entry->cutbuffer == NULL || entry->cutbuffer_len < size) {
@@ -471,10 +511,24 @@
 
 void gui_entry_move_pos(GUI_ENTRY_REC *entry, int pos)
 {
+	int newpos;
+
         g_return_if_fail(entry != NULL);
 
-	if (entry->pos+pos >= 0 && entry->pos+pos <= entry->text_len)
-		entry->pos += pos;
+	/* move cursor with big5 charset */
+	newpos = _fix_big5_pos(entry->text, entry->pos, -1);
+	if (pos > 0) {
+		while (pos > 0 && newpos < entry->text_len) {
+			newpos = _fix_big5_pos(entry->text, newpos+1, 1);
+			pos --;
+		}
+	} else {
+		while (pos < 0 && newpos > 0) {
+			newpos = _fix_big5_pos(entry->text, newpos-1, -1);
+			pos ++;
+		}
+	}
+	entry->pos = newpos;
 
 	gui_entry_fix_cursor(entry);
 	gui_entry_draw(entry);
