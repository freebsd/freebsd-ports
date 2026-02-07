--- ./code/q3_ui/ui_saveconfig.c.orig	Wed May 31 18:55:11 2006
+++ ./code/q3_ui/ui_saveconfig.c	Wed May 31 19:08:05 2006
@@ -85,7 +85,7 @@
 		return;
 	}
 
-	COM_StripExtension(saveConfig.savename.field.buffer, configname );
+	COM_StripExtension(saveConfig.savename.field.buffer, configname, sizeof(configname) );
 	trap_Cmd_ExecuteText( EXEC_APPEND, va( "writeconfig %s.cfg\n", configname ) );
 	UI_PopMenu();
 }
