--- client/menu.c.orig	Tue Dec 27 10:06:52 2005
+++ client/menu.c	Thu Mar 22 00:36:51 2007
@@ -898,7 +898,7 @@
 
 void Multiplayer_MenuInit( void )
 {
-	static qboolean PlayerConfig_ScanDirectories(void);
+	qboolean PlayerConfig_ScanDirectories(void);
 	if (!server_menu)
 		server_menu = Cvar_Get ("server_menu", "1", 0);
 
@@ -4784,7 +4784,7 @@
 	return false;
 }
 
-static qboolean PlayerConfig_ScanDirectories( void )
+qboolean PlayerConfig_ScanDirectories( void )
 {
 	char findname[1024];
 	char scratch[1024];
