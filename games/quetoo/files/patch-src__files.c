--- src/files.c.orig	Thu Jun 22 00:26:09 2006
+++ src/files.c	Thu Jul 27 17:22:54 2006
@@ -490,8 +490,9 @@
 		Cvar_FullSet("gamedir", dir, CVAR_SERVERINFO | CVAR_NOSET);
 		if(fs_cddir->string[0])
 			FS_AddGameDirectory(va("%s/%s", fs_cddir->string, dir));
-		FS_AddGameDirectory(va(PKGLIBDIR"/%s", dir));
 		FS_AddGameDirectory(va(PKGDATADIR"/%s", dir));
+		FS_AddGameDirectory(va(PKGLIBDIR"/%s", dir));
+		FS_AddGameDirectory(va("%s/%s", fs_basedir->string, dir));
 		FS_AddHomeAsGameDirectory(dir);
 	}
 }
@@ -682,20 +683,13 @@
 	Cmd_AddCommand("path", FS_Path_f);
 	Cmd_AddCommand("link", FS_Link_f);
 	Cmd_AddCommand("dir", FS_Dir_f);
-	
+
 	//
 	// basedir <path>
 	// allows the game to run from outside the data tree
 	//
 	fs_basedir = Cvar_Get("basedir", ".", CVAR_NOSET);
-	
-	//export q2 home, adding it to search path if necessary
-	if(fs_basedir->string && strcmp(fs_basedir->string, ".")){
-		setenv("QUAKE2_HOME", fs_basedir->string, 0);
-		FS_AddGameDirectory(fs_basedir->string);
-	}
-	else setenv("QUAKE2_HOME", PKGDATADIR, 0);
-	
+
 	//
 	// cddir <path>
 	// Logically concatenates the cddir after the basedir for
@@ -704,13 +698,20 @@
 	fs_cddir = Cvar_Get("cddir", "", CVAR_NOSET);
 	if(fs_cddir->string[0])
 		FS_AddGameDirectory(va("%s/"BASEDIRNAME, fs_cddir->string));
-		
+
 	//
 	// add baseq2 to search path
 	//
-	FS_AddGameDirectory(PKGLIBDIR"/"BASEDIRNAME);
 	FS_AddGameDirectory(PKGDATADIR"/"BASEDIRNAME);
-	
+	FS_AddGameDirectory(PKGLIBDIR"/"BASEDIRNAME);
+
+	//export q2 home, adding it to search path if necessary
+	if(fs_basedir->string && strcmp(fs_basedir->string, ".")){
+		setenv("QUAKE2_HOME", fs_basedir->string, 0);
+		FS_AddGameDirectory(fs_basedir->string);
+	}
+	else setenv("QUAKE2_HOME", PKGDATADIR, 0);
+
 	//
 	// then add a '.quake2/baseq2' directory in home directory by default
 	//
