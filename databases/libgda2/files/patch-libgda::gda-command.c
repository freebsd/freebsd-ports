--- libgda/gda-command.c.orig	Mon Dec  1 14:58:32 2003
+++ libgda/gda-command.c	Mon Dec  1 14:59:30 2003
@@ -100,8 +100,9 @@
 GdaCommand *
 gda_command_copy (GdaCommand *cmd)
 {
+	GdaCommand *new_cmd;
 	g_return_val_if_fail (cmd != NULL, NULL);
-	GdaCommand *new_cmd = gda_command_new (gda_command_get_text (cmd),
+	new_cmd = gda_command_new (gda_command_get_text (cmd),
 					       gda_command_get_command_type (cmd),
 					       gda_command_get_options (cmd));
 	gda_command_set_transaction (new_cmd,
