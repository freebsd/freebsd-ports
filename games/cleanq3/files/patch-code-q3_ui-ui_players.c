--- ./code/q3_ui/ui_players.c.orig	Wed May 31 20:52:07 2006
+++ ./code/q3_ui/ui_players.c	Wed May 31 20:55:05 2006
@@ -69,13 +69,13 @@
 
 	if ( weaponNum == WP_MACHINEGUN || weaponNum == WP_GAUNTLET || weaponNum == WP_BFG ) {
 		strcpy( path, item->world_model[0] );
-		COM_StripExtension( path, path );
+		COM_StripExtension( path, path, sizeof(path) );
 		strcat( path, "_barrel.md3" );
 		pi->barrelModel = trap_R_RegisterModel( path );
 	}
 
 	strcpy( path, item->world_model[0] );
-	COM_StripExtension( path, path );
+	COM_StripExtension( path, path, sizeof(path) );
 	strcat( path, "_flash.md3" );
 	pi->flashModel = trap_R_RegisterModel( path );
 
