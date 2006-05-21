--- ./NQ/common.c.orig	Mon Mar 13 22:02:46 2006
+++ ./NQ/common.c	Sun May 14 16:20:57 2006
@@ -1680,9 +1680,13 @@
 static void
 COM_InitFilesystem(void)
 {
+    char	*home;
+    char	homepath[MAX_OSPATH];
     int i, j;
     searchpath_t *search;
 
+    home = getenv("HOME");
+
 //
 // -basedir <path>
 // Overrides the system supplied base directory (under GAMENAME)
@@ -1691,7 +1695,7 @@
     if (i && i < com_argc - 1)
 	strcpy(com_basedir, com_argv[i + 1]);
     else
-	strcpy(com_basedir, host_parms.basedir);
+	strcpy(com_basedir, DATADIR);
 
     j = strlen(com_basedir);
 
@@ -1719,6 +1723,8 @@
 // start up with GAMENAME by default (id1)
 //
     COM_AddGameDirectory(va("%s/" GAMENAME, com_basedir));
+    if (home != NULL)
+	COM_AddGameDirectory(va("%s/.tyrquake/" GAMENAME, home));
 
     if (COM_CheckParm("-rogue"))
 	COM_AddGameDirectory(va("%s/rogue", com_basedir));
@@ -1733,6 +1739,15 @@
     if (i && i < com_argc - 1) {
 	com_modified = true;
 	COM_AddGameDirectory(va("%s/%s", com_basedir, com_argv[i + 1]));
+    }
+
+    if (home != NULL) {
+	snprintf(homepath, sizeof(homepath), "%s/.tyrquake/%s",
+	  home, strrchr(com_basedir, '/') + 1 ?
+	  strrchr(com_basedir, '/') + 1 : GAMENAME);
+	COM_CreatePath(homepath);
+	Sys_mkdir(homepath);
+	COM_AddGameDirectory(homepath);
     }
 //
 // -path <dir or packfile> [<dir or packfile>] ...
