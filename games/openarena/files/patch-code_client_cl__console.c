--- code/client/cl_console.c.orig	2011-12-24 12:29:31 UTC
+++ code/client/cl_console.c
@@ -172,7 +172,9 @@ void Con_Dump_f (void)
 	int		l, x, i;
 	short	*line;
 	fileHandle_t	f;
-	char	buffer[1024];
+	int		bufferlen;
+	char	*buffer;
+	char	filename[MAX_QPATH];
 
 	if (Cmd_Argc() != 2)
 	{
@@ -180,15 +182,24 @@ void Con_Dump_f (void)
 		return;
 	}
 
-	Com_Printf ("Dumped console text to %s.\n", Cmd_Argv(1) );
+	Q_strncpyz( filename, Cmd_Argv( 1 ), sizeof( filename ) );
+	COM_DefaultExtension( filename, sizeof( filename ), ".txt" );
 
-	f = FS_FOpenFileWrite( Cmd_Argv( 1 ) );
+	if (!COM_CompareExtension(filename, ".txt"))
+	{
+		Com_Printf("Con_Dump_f: Only the \".txt\" extension is supported by this command!\n");
+		return;
+	}
+
+	f = FS_FOpenFileWrite( filename );
 	if (!f)
 	{
-		Com_Printf ("ERROR: couldn't open.\n");
+		Com_Printf ("ERROR: couldn't open %s.\n", filename);
 		return;
 	}
 
+	Com_Printf ("Dumped console text to %s.\n", filename );
+
 	// skip empty lines
 	for (l = con.current - con.totallines + 1 ; l <= con.current ; l++)
 	{
@@ -214,10 +225,15 @@ void Con_Dump_f (void)
 			else
 				break;
 		}
-		strcat( buffer, "\n" );
+#ifdef _WIN32
+		Q_strcat(buffer, bufferlen, "\r\n");
+#else
+		Q_strcat(buffer, bufferlen, "\n");
+#endif
 		FS_Write(buffer, strlen(buffer), f);
 	}
 
+	Hunk_FreeTempMemory( buffer );
 	FS_FCloseFile( f );
 }
 
