--- code/qcommon/files.c.orig	Fri Jan 26 19:58:26 2007
+++ code/qcommon/files.c	Fri Jan 26 20:07:18 2007
@@ -2503,7 +2503,7 @@
 		sorted[i] = pakfiles[i];
 	}
 
-	qsort( sorted, numfiles, 4, paksort );
+	qsort( sorted, numfiles, sizeof(sorted[0]), paksort );
 
 	for ( i = 0 ; i < numfiles ; i++ ) {
 		pakfile = FS_BuildOSPath( path, dir, sorted[i] );
@@ -2763,6 +2763,7 @@
 	if (fs_basepath->string[0]) {
 		FS_AddGameDirectory( fs_basepath->string, gameName );
 	}
+	FS_AddGameDirectory( LIBDIR, gameName );
   // fs_homepath is somewhat particular to *nix systems, only add if relevant
   // NOTE: same filtering below for mods and basegame
 	if (fs_basepath->string[0] && Q_stricmp(fs_homepath->string,fs_basepath->string)) {
@@ -2777,6 +2778,7 @@
 		if (fs_basepath->string[0]) {
 			FS_AddGameDirectory(fs_basepath->string, fs_basegame->string);
 		}
+		FS_AddGameDirectory(LIBDIR, fs_basegame->string);
 		if (fs_homepath->string[0] && Q_stricmp(fs_homepath->string,fs_basepath->string)) {
 			FS_AddGameDirectory(fs_homepath->string, fs_basegame->string);
 		}
@@ -2790,6 +2792,7 @@
 		if (fs_basepath->string[0]) {
 			FS_AddGameDirectory(fs_basepath->string, fs_gamedirvar->string);
 		}
+		FS_AddGameDirectory(LIBDIR, fs_gamedirvar->string);
 		if (fs_homepath->string[0] && Q_stricmp(fs_homepath->string,fs_basepath->string)) {
 			FS_AddGameDirectory(fs_homepath->string, fs_gamedirvar->string);
 		}
