--- src/fe-text/gui-entry.c.orig	Sun Mar  4 02:04:10 2001
+++ src/fe-text/gui-entry.c	Thu Nov  1 23:38:28 2001
@@ -148,10 +148,35 @@
 	entry_update();
 }
 
+#ifdef WANT_BIG5
+int gui_is_big5(char *str, int pos)
+{
+  int a;
+  
+  if(pos < 0)
+    return 0;
+  for(a = 0; a < pos;)
+  {
+    if(str[0] == '\0')
+      break;
+    if(is_big5(str[a], str[a + 1]))
+      a += 2;
+    else
+      a ++;
+  }
+  return ((a == pos) && is_big5(str[a], str[a + 1]));
+}
+#endif WANT_BIG5
+
 void gui_entry_erase(int size)
 {
 	if (pos < size) return;
 
+#ifdef WANT_BIG5
+	if (gui_is_big5(entry->str, pos - 2))
+		size++;
+#endif WANT_BIG5
+
 	pos -= size;
 	g_string_erase(entry, pos, size);
 
@@ -217,6 +242,13 @@
 
 void gui_entry_move_pos(int p)
 {
+#ifdef WANT_BIG5
+	if (p > 0 && gui_is_big5(entry->str, pos))
+		p++;
+	else if (p < 0 && gui_is_big5(entry->str, pos - 2))
+		p--;
+#endif WANT_BIG5
+
 	if (pos+p >= 0 && pos+p <= entry->len)
 		pos += p;
 
