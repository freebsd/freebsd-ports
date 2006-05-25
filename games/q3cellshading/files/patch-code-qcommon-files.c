--- code/qcommon/files.c.orig	Thu May 25 16:39:34 2006
+++ code/qcommon/files.c	Thu May 25 16:41:43 2006
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
