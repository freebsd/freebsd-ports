--- src/fe-text/gui-entry.c.orig	Sat Feb 16 19:10:11 2002
+++ src/fe-text/gui-entry.c	Sun Mar  3 10:29:10 2002
@@ -67,6 +69,27 @@
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
@@ -84,6 +107,8 @@
 		entry->scrstart = entry->pos - entry->scrpos;
 	}
 
+	entry->scrstart = _fix_big5_pos(entry->text, entry->scrstart, -1);
+
 	if (old_scrstart != entry->scrstart)
                 entry->redraw_needed_from = 0;
 }
@@ -335,11 +360,18 @@
 
 void gui_entry_erase(GUI_ENTRY_REC *entry, int size)
 {
+	int newpos;
+
         g_return_if_fail(entry != NULL);
 
 	if (entry->pos < size)
 		return;
 
+	/* recount the erase size with big5 charsets */
+	for (newpos = entry->pos; newpos >= 0 && size > 0; size--)
+		newpos = _fix_big5_pos(entry->text, newpos-1, -1);
+	size = entry->pos - newpos;
+
         /* put erased text to cutbuffer */
 	if (entry->cutbuffer == NULL || entry->cutbuffer_len < size) {
 		g_free(entry->cutbuffer);
@@ -461,10 +493,24 @@
 
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
