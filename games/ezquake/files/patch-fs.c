--- fs.c.orig
+++ fs.c
@@ -63,6 +63,8 @@
 char	com_homedir[MAX_PATH];		// something really long C:/Documents and Settings/qqshka
 char	userdirfile[MAX_OSPATH] = {0};
 char	com_userdir[MAX_OSPATH] = {0};
+char	com_q1dir[MAX_OSPATH];		// /usr/local/share/quake
+char	com_datadir[MAX_OSPATH];	// /usr/local/share/ezquake
 int		userdir_type = -1;
 
 searchpath_t	*fs_searchpaths = NULL;
@@ -616,6 +618,12 @@
 	// Flush all data, so it will be forced to reload.
 	Cache_Flush ();
 
+	snprintf(com_q1dir, sizeof(com_q1dir), "%s/%s", Q1DIR, dir);
+	FS_AddGameDirectory(com_q1dir, FS_LOAD_FILE_ALL);
+
+	snprintf(com_datadir, sizeof(com_datadir), "%s/%s", DATADIR, dir);
+	FS_AddGameDirectory(com_datadir, FS_LOAD_FILE_ALL);
+
 	snprintf(com_gamedir, sizeof(com_gamedir), "%s/%s", com_basedir, dir);
 
 	FS_AddGameDirectory(com_gamedir, FS_LOAD_FILE_ALL);
@@ -699,6 +707,8 @@
 #elif defined(__linux__)
 		if (!Sys_fullpath(com_basedir, "/proc/self/exe", sizeof(com_basedir)))
 			Sys_Error("FS_InitFilesystemEx: Sys_fullpath failed");
+#elif defined(__FreeBSD__)
+		snprintf(com_basedir, sizeof(com_basedir), "%s/.ezquake/", getenv("HOME") ? getenv("HOME") : ".");
 #else
 		com_basedir[0] = 0; // FIXME: MAC / FreeBSD
 #endif
@@ -717,12 +727,11 @@
 		strlcpy (com_basedir, COM_Argv(i + 1), sizeof(com_basedir));
 	}
  	else { // made com_basedir equa to cwd
-//#ifdef __FreeBSD__
-//		strlcpy(com_basedir, DATADIR, sizeof(com_basedir) - 1);
-//#else
-
+#ifdef __FreeBSD__
+		snprintf(com_basedir, sizeof(com_basedir), "%s/.ezquake/", getenv("HOME") ? getenv("HOME") : ".");
+#else
 		Sys_getcwd(com_basedir, sizeof(com_basedir) - 1); // FIXME strlcpy (com_basedir, ".", sizeof(com_basedir)); ?
-//#endif
+#endif
 	}
 
 	for (i = 0; i < (int) strlen(com_basedir); i++)
@@ -767,6 +776,14 @@
 	}
 
 	// start up with id1 by default
+	snprintf(&tmp_path[0], sizeof(tmp_path), "%s/%s", Q1DIR, "id1");
+	FS_AddGameDirectory(tmp_path, FS_LOAD_FILE_ALL);
+	snprintf(&tmp_path[0], sizeof(tmp_path), "%s/%s", Q1DIR, "qw");
+	FS_AddGameDirectory(tmp_path, FS_LOAD_FILE_ALL);
+	snprintf(&tmp_path[0], sizeof(tmp_path), "%s/%s", DATADIR, "ezquake");
+	FS_AddGameDirectory(tmp_path, FS_LOAD_FILE_ALL);
+	snprintf(&tmp_path[0], sizeof(tmp_path), "%s/%s", DATADIR, "qw");
+	FS_AddGameDirectory(tmp_path, FS_LOAD_FILE_ALL);
 	snprintf(&tmp_path[0], sizeof(tmp_path), "%s/%s", com_basedir, "id1");
 	FS_AddGameDirectory(tmp_path, FS_LOAD_FILE_ALL);
 	snprintf(&tmp_path[0], sizeof(tmp_path), "%s/%s", com_basedir, "ezquake");
