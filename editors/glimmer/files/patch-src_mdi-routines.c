--- src/mdi-routines.c.orig	Tue May  7 13:35:06 2002
+++ src/mdi-routines.c	Tue May  7 13:40:16 2002
@@ -150,7 +150,7 @@
         length = text->length;
         line = text->line_number + 1;
         lines = GTK_EXTEXT (cur_file->text)->line_count + 1;
-        if (pos >= 0 && pos <= text->length && text->length > 0)
+        if (pos >= 0 && pos < text->length && text->length > 0)
             cur_char = GTK_EXTEXT_INDEX (text, pos);
         else
             cur_char = 0;
@@ -166,7 +166,10 @@
             else
                 gtk_widget_set_sensitive (search_menu_match, TRUE);
 
-            cur_char = GTK_EXTEXT_INDEX (text, pos);
+	    if (pos < text->length)
+            	cur_char = GTK_EXTEXT_INDEX (text, pos);
+	    else
+		cur_char = 0;
             if (cur_char < 1 || !strchr ("{[()]}", cur_char) || length < 1)
                 gtk_widget_set_sensitive (search_menu_select, FALSE);
             else
