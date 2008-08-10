--- ./code/qcommon/files.c.orig	2008-06-11 18:33:07.000000000 -0300
+++ ./code/qcommon/files.c	2008-06-27 20:35:32.000000000 -0300
@@ -2732,6 +2732,7 @@
 	if (fs_basepath->string[0]) {
 		FS_AddGameDirectory( fs_basepath->string, gameName );
 	}
+	FS_AddGameDirectory( LIBDIR, gameName );
 	// fs_homepath is somewhat particular to *nix systems, only add if relevant
 	
 	#ifdef MACOS_X
@@ -2751,6 +2752,7 @@
 		if (fs_basepath->string[0]) {
 			FS_AddGameDirectory(fs_basepath->string, fs_basegame->string);
 		}
+		FS_AddGameDirectory(LIBDIR, fs_basegame->string);
 		if (fs_homepath->string[0] && Q_stricmp(fs_homepath->string,fs_basepath->string)) {
 			FS_AddGameDirectory(fs_homepath->string, fs_basegame->string);
 		}
@@ -2761,6 +2763,7 @@
 		if (fs_basepath->string[0]) {
 			FS_AddGameDirectory(fs_basepath->string, fs_gamedirvar->string);
 		}
+		FS_AddGameDirectory(LIBDIR, fs_gamedirvar->string);
 		if (fs_homepath->string[0] && Q_stricmp(fs_homepath->string,fs_basepath->string)) {
 			FS_AddGameDirectory(fs_homepath->string, fs_gamedirvar->string);
 		}
