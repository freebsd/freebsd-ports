--- fs.c.orig	2008-04-27 17:51:50.000000000 -0300
+++ fs.c	2008-05-06 20:22:16.000000000 -0300
@@ -1022,6 +1022,8 @@
 		FS_AddGameDirectory(com_basedir, dir);
 	}
 #else
+	FS_AddGameDirectory(va("%s/%s", Q1DIR, dir), FS_LOAD_FILE_ALL);
+	FS_AddGameDirectory(va("%s/%s", DATADIR, dir), FS_LOAD_FILE_ALL);
 	FS_AddGameDirectory(va("%s/%s", com_basedir, dir), FS_LOAD_FILE_ALL);
 	if (*com_homedir) {
 		FS_AddHomeDirectory(va("%s/%s", com_homedir, dir), FS_LOAD_FILE_ALL);
@@ -1095,7 +1097,7 @@
 		if (!Sys_fullpath(com_basedir, "/proc/self/exe", sizeof(com_basedir)))
 			Sys_Error("FS_InitFilesystemEx: Sys_fullpath failed");
 #else
-		com_basedir[0] = 0; // FIXME: MAC / FreeBSD
+		snprintf(com_basedir, sizeof(com_basedir), "%s/.ezquake/", getenv("HOME") ? getenv("HOME") : ".");
 #endif
 
 		// strip ezquake*.exe, we need only path
@@ -1116,7 +1118,7 @@
 //		strlcpy(com_basedir, DATADIR, sizeof(com_basedir) - 1);
 //#else
 
-		Sys_getcwd(com_basedir, sizeof(com_basedir) - 1); // FIXME strlcpy (com_basedir, ".", sizeof(com_basedir)); ?
+		snprintf(com_basedir, sizeof(com_basedir), "%s/.ezquake/", getenv("HOME") ? getenv("HOME") : ".");
 //#endif
 	}
 
@@ -1176,6 +1178,10 @@
 	FS_AddGameDirectory(com_basedir, "ezquake");
 	FS_AddGameDirectory(com_basedir, "qw");
 #else
+	FS_AddGameDirectory(va("%s/%s", Q1DIR, "id1"),     FS_LOAD_FILE_ALL);
+	FS_AddGameDirectory(va("%s/%s", Q1DIR, "qw"),      FS_LOAD_FILE_ALL);
+	FS_AddGameDirectory(va("%s/%s", DATADIR, "ezquake"), FS_LOAD_FILE_ALL);
+	FS_AddGameDirectory(va("%s/%s", DATADIR, "qw"),      FS_LOAD_FILE_ALL);
 	FS_AddGameDirectory(va("%s/%s", com_basedir, "id1"),     FS_LOAD_FILE_ALL);
 	FS_AddGameDirectory(va("%s/%s", com_basedir, "ezquake"), FS_LOAD_FILE_ALL);
 	FS_AddGameDirectory(va("%s/%s", com_basedir, "qw"),      FS_LOAD_FILE_ALL);
