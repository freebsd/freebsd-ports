--- ./client/menu.c.orig	Tue Dec 11 18:57:14 2007
+++ ./client/menu.c	Wed Dec 12 00:31:03 2007
@@ -5104,143 +5104,16 @@
 
 static void PlayerConfig_ScanDirectories( void )
 {
-	char findname[1024];
 	char scratch[1024];
 	int ndirs = 0, npms = 0;
 	char **dirnames;
 	int i;
 
-	extern char **FS_ListFiles( char *, int *, unsigned, unsigned );
+	extern char **FS_ListFiles2( char *, int *, unsigned, unsigned );
 
 	s_numplayermodels = 0;
 
-	//get dirs from gamedir first.
-
-	Com_sprintf( findname, sizeof(findname), "%s/players/*.*", FS_Gamedir() );
-
-	dirnames = FS_ListFiles( findname, &ndirs, SFF_SUBDIR, 0 );
-	
-	if ( dirnames ) {
-		
-		/*
-		** go through the subdirectories
-		*/
-		npms = ndirs;
-		if ( npms > MAX_PLAYERMODELS )
-			npms = MAX_PLAYERMODELS;
-
-		for ( i = 0; i < npms; i++ )
-		{
-			int k, s;
-			char *a, *b, *c;
-			char **pcxnames;
-			char **skinnames;
-			int npcxfiles;
-			int nskins = 0;
-
-			if ( dirnames[i] == 0 )
-				continue;
-
-			// verify the existence of tris.md2
-			strcpy( scratch, dirnames[i] );
-			strcat( scratch, "/tris.md2" );
-			if ( !Sys_FindFirst( scratch, 0, SFF_SUBDIR | SFF_HIDDEN | SFF_SYSTEM ) )
-			{
-				free( dirnames[i] );
-				dirnames[i] = 0;
-				Sys_FindClose();
-				continue;
-			}
-			Sys_FindClose();
-
-			// verify the existence of at least one skin
-			strcpy( scratch, dirnames[i] );
-			strcat( scratch, "/*.tga" );
-			pcxnames = FS_ListFiles( scratch, &npcxfiles, 0, SFF_SUBDIR | SFF_HIDDEN | SFF_SYSTEM );
-
-			if ( !pcxnames )
-			{
-				free( dirnames[i] );
-				dirnames[i] = 0;
-				continue;
-			}
-
-			// count valid skins, which consist of a skin with a matching "_i" icon
-			for ( k = 0; k < npcxfiles-1; k++ )
-			{
-				if ( !strstr( pcxnames[k], "_i.tga" ) )
-				{
-					if ( IconOfSkinExists( pcxnames[k], pcxnames, npcxfiles - 1 ) )
-					{
-						nskins++;
-					}
-				}
-			}
-			if ( !nskins )
-				continue;
-
-			skinnames = malloc( sizeof( char * ) * ( nskins + 1 ) );
-			memset( skinnames, 0, sizeof( char * ) * ( nskins + 1 ) );
-
-			// copy the valid skins
-			for ( s = 0, k = 0; k < npcxfiles-1; k++ )
-			{
-				char *a, *b, *c;
-
-				if ( !strstr( pcxnames[k], "_i.tga" ) )
-				{
-					if ( IconOfSkinExists( pcxnames[k], pcxnames, npcxfiles - 1 ) )
-					{
-						a = strrchr( pcxnames[k], '/' );
-						b = strrchr( pcxnames[k], '\\' );
-
-						if ( a > b )
-							c = a;
-						else
-							c = b;
-
-						strcpy( scratch, c + 1 );
-
-						if ( strrchr( scratch, '.' ) )
-							*strrchr( scratch, '.' ) = 0;
-
-						skinnames[s] = strdup( scratch );
-						s++;
-					}
-				}
-			}
-
-			// at this point we have a valid player model
-			s_pmi[s_numplayermodels].nskins = nskins;
-			s_pmi[s_numplayermodels].skindisplaynames = skinnames;
-
-			// make short name for the model
-			a = strrchr( dirnames[i], '/' );
-			b = strrchr( dirnames[i], '\\' );
-
-			if ( a > b )
-				c = a;
-			else
-				c = b;
-
-			strncpy( s_pmi[s_numplayermodels].displayname, c + 1, MAX_DISPLAYNAME-1 );
-			strcpy( s_pmi[s_numplayermodels].directory, c + 1 );
-
-			FreeFileList( pcxnames, npcxfiles );
-
-			s_numplayermodels++;
-		}
-		if ( dirnames )
-			FreeFileList( dirnames, ndirs );
-	}
-
-	/*
-	** get a list of directories from basedir
-	*/
-
-	Com_sprintf( findname, sizeof(findname), "%s/players/*.*", BASEDIRNAME);
-
-	 dirnames = FS_ListFiles( findname, &ndirs, SFF_SUBDIR, 0 );
+	dirnames = FS_ListFiles2( "players/*.*", &ndirs, SFF_SUBDIR, 0 );
 
 	if ( !dirnames )
 		return;
