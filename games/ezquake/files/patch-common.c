--- common.c.orig	Fri Jan  4 12:29:52 2008
+++ common.c	Fri Jan  4 12:41:04 2008
@@ -2012,7 +2012,7 @@
 		if (!Sys_fullpath(com_basedir, "/proc/self/exe", sizeof(com_basedir)))
 			Sys_Error("FS_InitFilesystemEx: Sys_fullpath failed");
 #else
-		com_basedir[0] = 0; // FIXME: MAC / FreeBSD
+		snprintf(com_basedir, sizeof(com_basedir), "%s/.ezquake/", getenv("HOME") ? getenv("HOME") : ".");
 #endif
 
 		// strip ezquake*.exe, we need only path
@@ -2029,12 +2029,7 @@
 		strlcpy (com_basedir, com_argv[i + 1], sizeof(com_basedir));
 	}
  	else { // made com_basedir equa to cwd
-//#ifdef __FreeBSD__
-//		strlcpy(com_basedir, DATADIR, sizeof(com_basedir) - 1);
-//#else
-
-		Sys_getcwd(com_basedir, sizeof(com_basedir) - 1); // FIXME strlcpy (com_basedir, ".", sizeof(com_basedir)); ?
-//#endif
+		snprintf(com_basedir, sizeof(com_basedir), "%s/.ezquake/", getenv("HOME") ? getenv("HOME") : ".");
 	}
 
 	for (i = 0; i < (int) strlen(com_basedir); i++)
@@ -2078,6 +2073,10 @@
 	}
 
 	// start up with id1 by default
+	FS_AddGameDirectory(DATADIR, "id1");
+	FS_AddGameDirectory(DATADIR, "ezquake");
+	FS_AddGameDirectory(DATADIR, "qw");
+
 	FS_AddGameDirectory(com_basedir, "id1");
 
 	FS_AddGameDirectory(com_basedir, "ezquake");
