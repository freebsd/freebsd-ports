--- src/fe-text/gui-readline.c.orig	Thu Nov 27 01:30:03 2003
+++ src/fe-text/gui-readline.c	Wed Apr  7 11:02:59 2004
@@ -187,7 +187,12 @@
 			out[utf16_char_to_utf8(arr[i], out)] = '\0';
 			g_string_append(str, out);
 		} else {
-			g_string_append_c(str, arr[i]);
+			if(term_type==TERM_TYPE_BIG5) {
+				if(arr[i]>0xff)
+					g_string_append_c(str, arr[i]>>8&0xff);
+				g_string_append_c(str, arr[i]&0xff);
+			} else
+				g_string_append_c(str, arr[i]);
 		}
 	}
 
@@ -620,9 +625,7 @@
 	char *text, *line;
 	int pos;
 
-	pos = gui_entry_get_pos(active_entry);
-
-        text = gui_entry_get_text(active_entry);
+        text = gui_entry_get_text_and_pos(active_entry, &pos);
 	line = word_complete(active_win, text, &pos, erase);
 	g_free(text);
 
@@ -648,9 +651,7 @@
 	char *text, *line;
 	int pos;
 
-	pos = gui_entry_get_pos(active_entry);
-
-        text = gui_entry_get_text(active_entry);
+        text = gui_entry_get_text_and_pos(active_entry, &pos);
 	line = auto_word_complete(text, &pos);
 	g_free(text);
 
