--- gtksourceview/gtksourceview.c.orig	Wed May  7 20:10:15 2003
+++ gtksourceview/gtksourceview.c	Wed May  7 20:10:28 2003
@@ -762,8 +762,9 @@
 			gtk_text_iter_forward_to_line_end (&cur);
 		while (!gtk_text_iter_starts_line (&cur))
 		{
+		    	gunichar c;
 			gtk_text_iter_backward_char (&cur);
-			gunichar c = gtk_text_iter_get_char (&cur);
+			c = gtk_text_iter_get_char (&cur);
 			if (!g_unichar_isspace (c))
 			{
 				/* We've gone one character too far. */
