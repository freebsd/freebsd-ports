--- code/qcommon/files.c.orig	2011-12-24 12:29:32 UTC
+++ code/qcommon/files.c
@@ -195,6 +195,9 @@ static const unsigned int missionpak_che
 	1438664554u
 };
 
+int dangerousPaksFound;
+char dangerousPakNames[MAX_ZPATH][MAX_SEARCH_PATHS];
+
 // if this is defined, the executable positively won't work with any paks other
 // than the demo pak, even if productid is present.  This is only used for our
 // last demo release to prevent the mac and linux users from using the demo
@@ -250,6 +253,7 @@ static  cvar_t          *fs_apppath;
 #endif
 
 static	cvar_t		*fs_basepath;
+static	cvar_t		*fs_libpath;
 static	cvar_t		*fs_basegame;
 static	cvar_t		*fs_gamedirvar;
 static	searchpath_t	*fs_searchpaths;
@@ -529,30 +533,32 @@ qboolean FS_CreatePath (char *OSPath) {
 
 /*
 =================
-FS_CheckFilenameIsNotExecutable
+FS_CheckFilenameIsMutable
 
-ERR_FATAL if trying to maniuplate a file with the platform library extension
+ERR_FATAL if trying to maniuplate a file with the platform library, QVM, or pk3 extension
 =================
  */
-static void FS_CheckFilenameIsNotExecutable( const char *filename,
+static void FS_CheckFilenameIsMutable( const char *filename,
 		const char *function )
 {
-	// Check if the filename ends with the library extension
-	if( !Q_stricmp( COM_GetExtension( filename ), DLL_EXT ) )
+	// Check if the filename ends with the library, QVM, or pk3 extension
+	if( COM_CompareExtension( filename, DLL_EXT )
+		|| COM_CompareExtension( filename, ".qvm" )
+		|| COM_CompareExtension( filename, ".pk3" ) )
 	{
 		Com_Error( ERR_FATAL, "%s: Not allowed to manipulate '%s' due "
-			"to %s extension\n", function, filename, DLL_EXT );
+			"to %s extension", function, filename, COM_GetExtension( filename ) );
 	}
 }
 
 /*
-===========
+=================
 FS_Remove
 
 ===========
 */
 void FS_Remove( const char *osPath ) {
-	FS_CheckFilenameIsNotExecutable( osPath, __func__ );
+	FS_CheckFilenameIsMutable( osPath, __func__ );
 
 	remove( osPath );
 }
@@ -564,7 +570,7 @@ FS_HomeRemove
 ===========
 */
 void FS_HomeRemove( const char *homePath ) {
-	FS_CheckFilenameIsNotExecutable( homePath, __func__ );
+	FS_CheckFilenameIsMutable( homePath, __func__ );
 
 	remove( FS_BuildOSPath( fs_homepath->string,
 			fs_gamedir, homePath ) );
@@ -643,7 +649,7 @@ fileHandle_t FS_SV_FOpenFileWrite( const
 		Com_Printf( "FS_SV_FOpenFileWrite: %s\n", ospath );
 	}
 
-	FS_CheckFilenameIsNotExecutable( ospath, __func__ );
+	FS_CheckFilenameIsMutable( ospath, __func__ );
 
 	if( FS_CreatePath( ospath ) ) {
 		return 0;
@@ -735,7 +741,7 @@ FS_SV_Rename
 
 ===========
 */
-void FS_SV_Rename( const char *from, const char *to ) {
+void FS_SV_Rename( const char *from, const char *to, qboolean safe ) {
 	char			*from_ospath, *to_ospath;
 
 	if ( !fs_searchpaths ) {
@@ -754,7 +760,11 @@ void FS_SV_Rename( const char *from, con
 		Com_Printf( "FS_SV_Rename: %s --> %s\n", from_ospath, to_ospath );
 	}
 
-	FS_CheckFilenameIsNotExecutable( to_ospath, __func__ );
+	FS_CheckFilenameIsMutable( to_ospath, __func__ );
+
+	if ( safe ) {
+		FS_CheckFilenameIsMutable( to_ospath, __func__ );
+	}
 
 	rename(from_ospath, to_ospath);
 }
@@ -784,7 +794,7 @@ void FS_Rename( const char *from, const 
 		Com_Printf( "FS_Rename: %s --> %s\n", from_ospath, to_ospath );
 	}
 
-	FS_CheckFilenameIsNotExecutable( to_ospath, __func__ );
+	FS_CheckFilenameIsMutable( to_ospath, __func__ );
 
 	rename(from_ospath, to_ospath);
 }
@@ -843,7 +853,7 @@ fileHandle_t FS_FOpenFileWrite( const ch
 		Com_Printf( "FS_FOpenFileWrite: %s\n", ospath );
 	}
 
-	FS_CheckFilenameIsNotExecutable( ospath, __func__ );
+	FS_CheckFilenameIsMutable( ospath, __func__ );
 
 	if( FS_CreatePath( ospath ) ) {
 		return 0;
@@ -891,7 +901,7 @@ fileHandle_t FS_FOpenFileAppend( const c
 		Com_Printf( "FS_FOpenFileAppend: %s\n", ospath );
 	}
 
-	FS_CheckFilenameIsNotExecutable( ospath, __func__ );
+	FS_CheckFilenameIsMutable( ospath, __func__ );
 
 	if( FS_CreatePath( ospath ) ) {
 		return 0;
@@ -963,6 +973,7 @@ int FS_FOpenFileRead( const char *filena
 	FILE			*temp;
 	int				l;
 	char demoExt[16];
+	qboolean isLocalConfig, isQVM;
 
 	hash = 0;
 
@@ -970,11 +981,22 @@ int FS_FOpenFileRead( const char *filena
 		Com_Error( ERR_FATAL, "Filesystem call made without initialization\n" );
 	}
 
+	isLocalConfig = !Q_stricmp(filename, "autoexec.cfg") || !Q_stricmp(filename, "q3config.cfg");
+	isQVM = COM_CompareExtension(filename, ".qvm");
+
 	if ( file == NULL ) {
 		// just wants to see if file is there
 		for ( search = fs_searchpaths ; search ; search = search->next ) {
 			//
 			if ( search->pack ) {
+				// autoexec.cfg and q3config.cfg can only be loaded outside of pk3 files.
+				if (isLocalConfig)
+					continue;
+
+				// QVMs can't be loaded from pk3 in the "download" directory
+				if (isQVM && !Q_stricmp(search->pack->pakGamename, "download"))
+					continue;
+
 				hash = FS_HashFileName(filename, search->pack->hashSize);
 			}
 			// is the element a pak file?
@@ -1040,6 +1062,14 @@ int FS_FOpenFileRead( const char *filena
 	for ( search = fs_searchpaths ; search ; search = search->next ) {
 		//
 		if ( search->pack ) {
+			// autoexec.cfg and q3config.cfg can only be loaded outside of pk3 files.
+			if (isLocalConfig)
+				continue;
+
+			// QVMs can't be loaded from pk3 in the "download" directory
+			if (isQVM && !Q_stricmp(search->pack->pakGamename, "download"))
+				continue;
+
 			hash = FS_HashFileName(filename, search->pack->hashSize);
 		}
 		// is the element a pak file?
@@ -1657,7 +1687,7 @@ Creates a new pak_t in the search chain 
 of a zip file.
 =================
 */
-static pack_t *FS_LoadZipFile(const char *zipfile, const char *basename)
+static pack_t *FS_LoadZipFile(const char *zipfile, const char *basename, const char *gamename )
 {
 	fileInPack_t	*buildBuffer;
 	pack_t			*pack;
@@ -1666,11 +1696,12 @@ static pack_t *FS_LoadZipFile(const char
 	unz_global_info gi;
 	char			filename_inzip[MAX_ZPATH];
 	unz_file_info	file_info;
-	int				i, len;
+	int				i, j, len;
 	long			hash;
 	int				fs_numHeaderLongs;
 	int				*fs_headerLongs;
 	char			*namePtr;
+	qboolean		alreadydangerous = qfalse;
 
 	fs_numHeaderLongs = 0;
 
@@ -1714,6 +1745,7 @@ static pack_t *FS_LoadZipFile(const char
 
 	Q_strncpyz( pack->pakFilename, zipfile, sizeof( pack->pakFilename ) );
 	Q_strncpyz( pack->pakBasename, basename, sizeof( pack->pakBasename ) );
+	Q_strncpyz( pack->pakGamename, gamename, sizeof( pack->pakGamename ) );
 
 	// strip .pk3 if needed
 	if ( strlen( pack->pakBasename ) > 4 && !Q_stricmp( pack->pakBasename + strlen( pack->pakBasename ) - 4, ".pk3" ) ) {
@@ -1730,6 +1762,30 @@ static pack_t *FS_LoadZipFile(const char
 		if (err != UNZ_OK) {
 			break;
 		}
+
+		if (!Q_stricmp(pack->pakGamename, "download") && (
+				COM_CompareExtension(filename_inzip, ".qvm") ||
+				!Q_stricmp(filename_inzip, "autoexec.cfg") ||
+				!Q_stricmp(filename_inzip, "q3config.cfg")))
+		{
+
+			for (j = 0; j < dangerousPaksFound; j++) {
+				if (!strcmp(dangerousPakNames[j], pack->pakBasename)) {
+					alreadydangerous = qtrue;
+					break;
+				}
+			}
+
+			if (!alreadydangerous) {
+				Q_strncpyz(dangerousPakNames[dangerousPaksFound], pack->pakBasename, MAX_ZPATH);
+				dangerousPaksFound++;
+			}
+
+			Com_Printf(S_COLOR_RED "Dangerous file %s found in %s\n",
+					filename_inzip,
+					pack->pakFilename);
+		}
+
 		if (file_info.uncompressed_size > 0) {
 			fs_headerLongs[fs_numHeaderLongs++] = LittleLong(file_info.crc);
 		}
@@ -1784,7 +1840,7 @@ qboolean FS_CompareZipChecksum(const cha
 	pack_t *thepak;
 	int index, checksum;
 	
-	thepak = FS_LoadZipFile(zipfile, "");
+	thepak = FS_LoadZipFile(zipfile, "", "");
 	
 	if(!thepak)
 		return qfalse;
@@ -2569,10 +2625,8 @@ void FS_AddGameDirectory( const char *pa
 
 	for ( i = 0 ; i < numfiles ; i++ ) {
 		pakfile = FS_BuildOSPath( path, dir, pakfiles[i] );
-		if ( ( pak = FS_LoadZipFile( pakfile, pakfiles[i] ) ) == 0 )
+		if ( ( pak = FS_LoadZipFile( pakfile, pakfiles[i], dir ) ) == 0 )
 			continue;
-		// store the game name for downloading
-		strcpy(pak->pakGamename, dir);
 		
 		fs_packFiles += pak->numfiles;
 
@@ -2854,11 +2908,14 @@ static void FS_Startup( const char *game
 
 	Com_Printf( "----- FS_Startup -----\n" );
 
+	dangerousPaksFound = 0;
+
 	fs_packFiles = 0;
 
 	fs_debug = Cvar_Get( "fs_debug", "0", 0 );
 	fs_basepath = Cvar_Get ("fs_basepath", Sys_DefaultInstallPath(), CVAR_INIT );
 	fs_basegame = Cvar_Get ("fs_basegame", "", CVAR_INIT );
+	fs_libpath = Cvar_Get ("fs_libpath", Sys_DefaultLibPath(), CVAR_INIT );
 	homePath = Sys_DefaultHomePath();
 	if (!homePath || !homePath[0]) {
 		homePath = fs_basepath->string;
@@ -2878,6 +2935,11 @@ static void FS_Startup( const char *game
 	if (fs_apppath->string[0])
 		FS_AddGameDirectory(fs_apppath->string, gameName);
 	#endif
+
+	// Search default library location if given
+	if (fs_libpath->string[0]) {
+		FS_AddGameDirectory ( fs_libpath->string, gameName );
+	}
 	
 	// NOTE: same filtering below for mods and basegame
 	if (fs_homepath->string[0] && Q_stricmp(fs_homepath->string,fs_basepath->string)) {
