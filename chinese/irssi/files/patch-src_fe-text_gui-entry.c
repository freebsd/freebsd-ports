--- src/fe-text/gui-entry.c.orig	Fri Apr 27 19:13:05 2001
+++ src/fe-text/gui-entry.c	Fri Apr 27 22:30:26 2001
@@ -152,6 +152,11 @@
 {
 	if (pos < size) return;
 
+#ifdef WANT_BIG5
+	if (is_big5(entry->str[pos-2], entry->str[pos-1]))
+		size++;
+#endif WANT_BIG5
+
 	pos -= size;
 	g_string_erase(entry, pos, size);
 
@@ -217,6 +222,13 @@
 
 void gui_entry_move_pos(int p)
 {
+#ifdef WANT_BIG5
+	if (p > 0 && is_big5 (entry->str[pos], entry->str[pos+1]))
+		p++;
+	else if (p < 0 && is_big5 (entry->str[pos-1], entry->str[pos]))
+		p--;
+#endif WANT_BIG5
+
 	if (pos+p >= 0 && pos+p <= entry->len)
 		pos += p;
 
