--- src/executer.c.orig	Tue Aug 31 00:40:58 2004
+++ src/executer.c	Tue Aug 31 00:41:25 2004
@@ -154,7 +154,7 @@
 	if(e->terminal)
 	{
 		gchar* escaped_cmd;
-		escaped_cmd = anjuta_util_escape_quotes(command);
+		escaped_cmd = command;
 		prop_set_with_key (e->props, "anjuta.current.command", escaped_cmd);
 
 #ifdef DEBUG
@@ -162,7 +162,7 @@
 #endif
 		
 		cmd = command_editor_get_command (app->command_editor, COMMAND_TERMINAL);
-		g_free(escaped_cmd);
+		/*g_free(escaped_cmd);*/
 	}
 	else
 	{
