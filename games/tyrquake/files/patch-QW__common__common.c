--- ./QW/common/common.c.orig	Mon Mar 13 22:03:06 2006
+++ ./QW/common/common.c	Sun May 14 16:23:22 2006
@@ -1794,8 +1794,12 @@
 static void
 COM_InitFilesystem(void)
 {
+    char	*home;
+    char	homepath[MAX_OSPATH];
     int i;
 
+    home = getenv("HOME");
+
 //
 // -basedir <path>
 // Overrides the system supplied base directory (under id1)
@@ -1804,13 +1808,22 @@
     if (i && i < com_argc - 1)
 	strcpy(com_basedir, com_argv[i + 1]);
     else
-	strcpy(com_basedir, host_parms.basedir);
+	strcpy(com_basedir, DATADIR);
 
 //
 // start up with id1 by default
 //
     COM_AddGameDirectory(va("%s/id1", com_basedir));
+    if (home != NULL)
+	COM_AddGameDirectory(va("%s/.tyrquake/id1", home));
+
     COM_AddGameDirectory(va("%s/qw", com_basedir));
+    if (home != NULL) {
+	snprintf(homepath, sizeof(homepath), "%s/.tyrquake/qw", home);
+	COM_CreatePath(homepath);
+	Sys_mkdir(homepath);
+	COM_AddGameDirectory(homepath);
+    }
 
     // any set gamedirs will be freed up to here
     com_base_searchpaths = com_searchpaths;
