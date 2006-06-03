--- ./code/renderer/tr_bsp.c.orig	Wed May 31 18:55:11 2006
+++ ./code/renderer/tr_bsp.c	Wed May 31 19:09:13 2006
@@ -1820,7 +1820,7 @@
 	Q_strncpyz( s_worldData.name, name, sizeof( s_worldData.name ) );
 
 	Q_strncpyz( s_worldData.baseName, COM_SkipPath( s_worldData.name ), sizeof( s_worldData.name ) );
-	COM_StripExtension( s_worldData.baseName, s_worldData.baseName );
+	COM_StripExtension( s_worldData.baseName, s_worldData.baseName , sizeof(s_worldData.baseName));
 
 	startMarker = ri.Hunk_Alloc(0, h_low);
 	c_gridVerts = 0;
