--- src/fe-text/gui-entry.c.orig	Sun Mar  4 02:04:10 2001
+++ src/fe-text/gui-entry.c	Sat Jan 26 20:38:19 2002
@@ -29,6 +29,28 @@
 static int prompt_hidden;
 static char *prompt;
 
+#ifdef WANT_BIG5
+#include "settings.h"
+
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
@@ -42,6 +64,14 @@
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
 
@@ -152,6 +182,12 @@
 {
 	if (pos < size) return;
 
+#ifdef WANT_BIG5
+	if (settings_get_bool("big5_cursor_movement"))
+	  if(size == 1 && gui_is_big5(entry->str, pos - 2))
+	    size++;
+#endif WANT_BIG5
+
 	pos -= size;
 	g_string_erase(entry, pos, size);
 
@@ -217,6 +253,16 @@
 
 void gui_entry_move_pos(int p)
 {
+#ifdef WANT_BIG5
+	if(settings_get_bool("big5_cursor_movement"))
+	{
+	  if (p == 1 && gui_is_big5(entry->str, pos))
+	    p++;
+	  else if (p == -1 && gui_is_big5(entry->str, pos - 2))
+	    p--;
+	}
+#endif WANT_BIG5
+
 	if (pos+p >= 0 && pos+p <= entry->len)
 		pos += p;
 
@@ -277,6 +323,9 @@
 	prompt = NULL; promptlen = 0;
 	permanent_prompt = FALSE;
         prompt_hidden = FALSE;
+#ifdef WANT_BIG5
+	settings_add_bool("fe-text", "big5_cursor_movement", FALSE);
+#endif WANT_BIG5
 }
 
 void gui_entry_deinit(void)

