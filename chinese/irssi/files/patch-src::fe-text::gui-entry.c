--- src/fe-text/gui-entry.c.orig	Sun Oct 26 13:45:02 2003
+++ src/fe-text/gui-entry.c	Thu Apr 29 14:33:53 2004
@@ -68,28 +68,107 @@
         g_free(entry);
 }
 
-/* Fixes the cursor position if it at big5_lo .
-   Direct: -1    ,  left shift 1 byte.
-   Direct: 0, +1 ,  right shift 1 byte.
-*/
-static int _fix_big5_pos(unichar *p, int pos, int direct)
-{
-	int newpos;
-
-	if (term_type != TERM_TYPE_BIG5)
-		return pos;
-
-	for (newpos = 0; newpos < pos && p[newpos] != 0; ) {
-		if (is_big5(p[newpos], p[newpos+1]))
-			newpos += 2;
-		else
-			newpos++;
+/* big5 functions */
+#define big5_width(ch) ((ch)>0xff ? 2:1)
+
+void unichars_to_big5(const unichar *str, char *out)
+{
+	for (; *str != '\0'; str++) {
+		if(*str>0xff)
+			*out++ = (*str>>8)&0xff;
+		*out++ = *str&0xff;
 	}
+	*out = '\0';
+}
+
+void unichars_to_big5_with_pos(const unichar *str, int spos, char *out, int *opos)
+{
+	const unichar *sstart = str;
+	char *ostart = out;
 
-	if (newpos != pos)
-		pos += direct > 0 ? 1 : -1;
+	*opos = 0;
+	while(*str != '\0')
+	{
+		if(*str > 0xff)
+			*out ++ = (*str >> 8) & 0xff;
+		*out ++ = *str & 0xff;
+		str ++;
+		if(str - sstart == spos)
+			*opos = out - ostart;
+	}
+	*out = '\0';
+}
 
-	return pos;
+int strlen_big5(const unsigned char *str)
+{
+	int len=0;
+
+	if(term_type!=TERM_TYPE_BIG5)
+		return strlen(str);
+	while(*str != '\0') {
+		if(is_big5(str[0],str[1]))
+			str++;
+		len++;
+		str++;
+	}
+	return len;
+}
+
+void big5_to_unichars(const char *str, unichar *out)
+{
+	const unsigned char *p = (const unsigned char *) str;
+
+	while(*p != '\0')
+		if (is_big5(p[0], p[1])) {
+			*out++ = p[0] << 8 | p[1];
+			p += 2;
+		} else
+			*out++ = *p++;
+	*out = '\0';
+}
+
+/* ----------------------------- */
+
+static int pos2scrpos(GUI_ENTRY_REC *entry, int pos)
+{
+	unichar *p;
+	int xpos=0;
+
+	for (p=entry->text;p-entry->text<pos;p++)
+		if (term_type == TERM_TYPE_BIG5)
+			xpos += big5_width(*p);
+		else if(entry->utf8)
+			xpos += utf8_width(*p);
+		else
+			xpos ++;
+
+	return xpos;
+}
+
+static int scrpos2pos(GUI_ENTRY_REC *entry, int pos)
+{
+	int i;
+	int xpos=0;
+
+	for(i=0; entry->text[i]; i++) {
+		int width;
+		unichar *p=entry->text+i;
+
+		if(term_type == TERM_TYPE_BIG5)
+			width = big5_width(*p);
+		else if(entry->utf8)
+			width = utf8_width(*p);
+		else
+			width = 1;
+		if(xpos+width>pos)
+			break;
+		xpos+=width;
+	}
+
+	if(xpos==pos)
+		return i;
+	else
+		return i-1;
 }
 
 /* Fixes the cursor position in screen */
@@ -97,20 +176,23 @@
 {
 	int old_scrstart;
 
-        old_scrstart = entry->scrstart;
-	if (entry->pos - entry->scrstart < entry->width-2 - entry->promptlen &&
-	    entry->pos - entry->scrstart > 0) {
-		entry->scrpos = entry->pos - entry->scrstart;
-	} else if (entry->pos < entry->width-1 - entry->promptlen) {
+	/* assume prompt len == prompt scrlen */
+	int start=pos2scrpos(entry,entry->scrstart);
+	int now=pos2scrpos(entry,entry->pos);
+
+	old_scrstart = entry->scrstart;
+	if (now-start < entry->width-2-entry->promptlen &&
+			now-start > 0)
+		entry->scrpos=now-start;
+	else if(now < entry->width-1-entry->promptlen) {
 		entry->scrstart = 0;
-		entry->scrpos = entry->pos;
+		entry->scrpos=now;
 	} else {
-		entry->scrpos = (entry->width - entry->promptlen)*2/3;
-		entry->scrstart = entry->pos - entry->scrpos;
+		entry->scrstart = scrpos2pos(entry,now-(entry->width - entry->promptlen)*2/3);
+		start=pos2scrpos(entry,entry->scrstart);
+		entry->scrpos=now-start;
 	}
 
-	entry->scrstart = _fix_big5_pos(entry->text, entry->scrstart, -1);
-
 	if (old_scrstart != entry->scrstart)
                 entry->redraw_needed_from = 0;
 }
@@ -120,7 +202,9 @@
 	const unichar *p;
 	int xpos, end_xpos;
 
-        xpos = entry->xpos + entry->promptlen + pos;
+	xpos = entry->xpos + entry->promptlen + 
+		pos2scrpos(entry, pos + entry->scrstart) - 
+		pos2scrpos(entry, entry->scrstart);
         end_xpos = entry->xpos + entry->width;
 	if (xpos > end_xpos)
                 return;
@@ -131,8 +215,16 @@
 	p = entry->scrstart + pos < entry->text_len ?
 		entry->text + entry->scrstart + pos : empty_str;
 	for (; *p != '\0'; p++) {
-		xpos += utf8_width(*p);
-		if (xpos > end_xpos)
+		if (entry->hidden)
+			xpos++;
+		else if(term_type == TERM_TYPE_BIG5)
+			xpos += big5_width(*p);
+		else if(entry->utf8)
+			xpos += utf8_width(*p);
+		else
+			xpos++;
+
+		if (xpos >= end_xpos)
 			break;
 
 		if (entry->hidden)
@@ -285,8 +377,34 @@
 	if (entry->utf8)
 		utf16_to_utf8(entry->text, buf);
 	else {
-		for (i = 0; i <= entry->text_len; i++)
-			buf[i] = entry->text[i];
+		if(term_type==TERM_TYPE_BIG5)
+			unichars_to_big5(entry->text, buf);
+		else
+			for (i = 0; i <= entry->text_len; i++)
+				buf[i] = entry->text[i];
+	}
+	return buf;
+}
+
+char *gui_entry_get_text_and_pos(GUI_ENTRY_REC *entry, int *pos)
+{
+	char *buf;
+        int i;
+
+	g_return_val_if_fail(entry != NULL, NULL);
+
+	buf = g_malloc(entry->text_len*6 + 1);
+	if (entry->utf8)
+		utf16_to_utf8_with_pos(entry->text, entry->pos, buf, pos);
+	else {
+		if(term_type==TERM_TYPE_BIG5)
+			unichars_to_big5_with_pos(entry->text, entry->pos, buf, pos);
+		else
+		{
+			for (i = 0; i <= entry->text_len; i++)
+				buf[i] = entry->text[i];
+			*pos = entry->pos;
+		}
 	}
 	return buf;
 }
@@ -301,7 +419,7 @@
 
         gui_entry_redraw_from(entry, entry->pos);
 
-	len = !entry->utf8 ? strlen(str) : strlen_utf8(str);
+	len = !entry->utf8 ? strlen_big5(str) : strlen_utf8(str);
         entry_text_grow(entry, len);
 
         /* make space for the string */
@@ -309,8 +427,13 @@
 		  (entry->text_len-entry->pos + 1) * sizeof(unichar));
 
 	if (!entry->utf8) {
-		for (i = 0; i < len; i++)
-                        entry->text[entry->pos+i] = str[i];
+		if (term_type == TERM_TYPE_BIG5) {
+			chr = entry->text[entry->pos+len];
+			big5_to_unichars(str, entry->text+entry->pos);
+			entry->text[entry->pos+len] = chr;
+		} else
+			for (i = 0; i < len; i++)
+				entry->text[entry->pos + i] = str[i];
 	} else {
                 chr = entry->text[entry->pos+len];
 		utf8_to_utf16(str, entry->text+entry->pos);
@@ -361,8 +484,12 @@
 	if (entry->utf8)
 		utf16_to_utf8(entry->cutbuffer, buf);
 	else {
-		for (i = 0; i <= entry->cutbuffer_len; i++)
-			buf[i] = entry->cutbuffer[i];
+		  if(term_type==TERM_TYPE_BIG5) {
+			  unichars_to_big5(entry->cutbuffer, buf);
+		  } else
+			  for (i = 0; i <= entry->cutbuffer_len; i++) {
+				  buf[i] = entry->cutbuffer[i];
+			  }
 	}
 	return buf;
 }
@@ -374,24 +501,17 @@
 	g_return_if_fail(entry != NULL);
 
 	for (newpos = gui_entry_get_pos(entry); newpos > pos; size++)
-		newpos = _fix_big5_pos(entry->text, newpos - 1, -1);
+		newpos = newpos - 1;
 	gui_entry_erase(entry, size, update_cutbuffer);
 }
 
 void gui_entry_erase(GUI_ENTRY_REC *entry, int size, int update_cutbuffer)
 {
-	int newpos;
-
         g_return_if_fail(entry != NULL);
 
 	if (entry->pos < size)
 		return;
 
-	/* recount the erase size with big5 charsets */
-	for (newpos = entry->pos; newpos > 0 && size > 0; size--)
-		newpos = _fix_big5_pos(entry->text, newpos-1, -1);
-	size = entry->pos - newpos;
-
 	if (update_cutbuffer) {
 		/* put erased text to cutbuffer */
 		if (entry->cutbuffer == NULL || entry->cutbuffer_len < size) {
@@ -513,26 +633,42 @@
 	gui_entry_draw(entry);
 }
 
-void gui_entry_move_pos(GUI_ENTRY_REC *entry, int pos)
+int gui_entry_linepos_to_pos(GUI_ENTRY_REC *entry, int linepos)
 {
-	int newpos;
-
-        g_return_if_fail(entry != NULL);
+	int pos, len;
 
-	/* move cursor with big5 charset */
-	newpos = _fix_big5_pos(entry->text, entry->pos, -1);
-	if (pos > 0) {
-		while (pos > 0 && newpos < entry->text_len) {
-			newpos = _fix_big5_pos(entry->text, newpos+1, 1);
-			pos--;
-		}
-	} else {
-		while (pos < 0 && newpos > 0) {
-			newpos = _fix_big5_pos(entry->text, newpos-1, -1);
-			pos++;
+	for(pos = 0, len = 0; len < linepos; pos++)
+	{
+		if(entry->utf8)
+	  		len += utf16_char_to_utf8(entry->text[pos], NULL);
+		else if(term_type == TERM_TYPE_BIG5)
+		{
+			len += (entry->text[pos] > 0xff ? 2 : 1);
 		}
+		else
+			len ++;
 	}
-	entry->pos = newpos;
+	return pos;
+}
+
+void gui_entry_set_linepos(GUI_ENTRY_REC *entry, int pos)
+{
+        g_return_if_fail(entry != NULL);
+
+	pos = gui_entry_linepos_to_pos(entry, pos);
+	if (pos >= 0 && pos <= entry->text_len)
+		entry->pos = pos;
+
+	gui_entry_fix_cursor(entry);
+	gui_entry_draw(entry);
+}
+
+void gui_entry_move_pos(GUI_ENTRY_REC *entry, int pos)
+{
+        g_return_if_fail(entry != NULL);
+
+	if (entry->pos+pos >= 0 && entry->pos+pos <= entry->text_len)
+		entry->pos += pos;
 
 	gui_entry_fix_cursor(entry);
 	gui_entry_draw(entry);
