--- src/fe-text/gui-entry.c.orig	Sun Mar  4 02:04:10 2001
+++ src/fe-text/gui-entry.c	Mon Nov  5 01:40:11 2001
@@ -29,6 +29,26 @@
 static int prompt_hidden;
 static char *prompt;
 
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
 static void entry_screenpos(void)
 {
 	if (pos-scrstart < COLS-2-promptlen && pos-scrstart > 0) {
@@ -42,6 +62,14 @@
 	} else {
 		scrpos = (COLS-promptlen)*2/3;
 		scrstart = pos-scrpos;
+#ifdef WANT_BIG5
+		if((scrstart > 0) &&
+		   gui_is_big5(entry->str, scrstart - 1))
+		{
+		  scrstart --;
+		  scrpos ++;
+		}
+#endif WANT_BIG5
 	}
 }
 
@@ -152,6 +180,11 @@
 {
 	if (pos < size) return;
 
+#ifdef WANT_BIG5
+	if (gui_is_big5(entry->str, pos - 2))
+		size++;
+#endif WANT_BIG5
+
 	pos -= size;
 	g_string_erase(entry, pos, size);
 
@@ -217,6 +250,13 @@
 
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
 
