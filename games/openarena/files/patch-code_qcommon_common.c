--- code/qcommon/common.c.orig	2011-12-24 12:29:32 UTC
+++ code/qcommon/common.c
@@ -2845,6 +2845,13 @@ void Com_WriteConfig_f( void ) {
 
 	Q_strncpyz( filename, Cmd_Argv(1), sizeof( filename ) );
 	COM_DefaultExtension( filename, sizeof( filename ), ".cfg" );
+
+	if (!COM_CompareExtension(filename, ".cfg"))
+	{
+		Com_Printf("Com_WriteConfig_f: Only the \".cfg\" extension is supported by this command!\n");
+		return;
+	}
+
 	Com_Printf( "Writing %s.\n", filename );
 	Com_WriteConfigToFile( filename );
 }
