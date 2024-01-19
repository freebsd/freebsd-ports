--- client/menu.c.orig	2005-12-27 13:06:52 UTC
+++ client/menu.c
@@ -898,7 +898,7 @@ static void StartNetworkServerFunc( void *unused )
 
 void Multiplayer_MenuInit( void )
 {
-	static qboolean PlayerConfig_ScanDirectories(void);
+	qboolean PlayerConfig_ScanDirectories(void);
 	if (!server_menu)
 		server_menu = Cvar_Get ("server_menu", "1", 0);
 
@@ -4784,7 +4784,7 @@ static qboolean IconOfSkinExists( char *skin, char **f
 	return false;
 }
 
-static qboolean PlayerConfig_ScanDirectories( void )
+qboolean PlayerConfig_ScanDirectories( void )
 {
 	char findname[1024];
 	char scratch[1024];
