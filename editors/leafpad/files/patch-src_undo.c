--- src/undo.c.orig	Thu Nov 18 17:04:27 2004
+++ src/undo.c	Sun Nov 21 12:21:08 2004
@@ -159,7 +159,8 @@
 		ui_tmp->command = command;
 		ui_tmp->start = start;
 		ui_tmp->end = end;
-		g_string_printf(undo_gstr, str);
+		undo_gstr = g_string_erase(undo_gstr, 0, -1);
+		g_string_append(undo_gstr, str);
 	} else 
 		undo_append_undo_info(buffer, command, start, end, g_strdup(str));
 	
