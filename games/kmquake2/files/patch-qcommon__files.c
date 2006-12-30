--- qcommon/files.c.orig	Thu Mar 23 06:30:01 2006
+++ qcommon/files.c	Sat Dec 30 01:23:45 2006
@@ -1314,7 +1314,7 @@
 	char	*homedir;		/* Home directory. */
 
 	if ((homedir = getenv("HOME")) != NULL) {
-		Com_sprintf(gdir, sizeof(gdir), "%s/.quake2/%s", homedir, dir);
+		Com_sprintf(gdir, sizeof(gdir), "%s/.kmquake2/%s", homedir, dir);
 		FS_AddGameDirectory(gdir);
 	}
 }
@@ -1468,16 +1468,7 @@
 	// basedir <path>
 	// allows the game to run from outside the data tree
 	//
-#if defined __unix__ 
-#ifdef DATADIR
-	fs_basedir = Cvar_Get("basedir", DATADIR, CVAR_NOSET);
-#else
-	fs_basedir = Cvar_Get("basedir", ".", CVAR_NOSET);
-#endif
-#endif
-#ifdef _WIN32
 	fs_basedir = Cvar_Get ("basedir", ".", CVAR_NOSET);
-#endif
 
 	//
 	// cddir <path>
@@ -1491,11 +1482,14 @@
 	//
 	// start up with baseq2 by default
 	//
-#ifdef LIBDIR // unix
+#ifdef DATADIR
+	FS_AddGameDirectory(va("%s/"BASEDIRNAME, DATADIR));
+#endif
+#ifdef LIBDIR
 	FS_AddGameDirectory(va("%s/"BASEDIRNAME, LIBDIR));
 #endif
 	FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );
-#ifdef DATADIR // unix
+#ifdef DATADIR
 	FS_AddHomeAsGameDirectory(BASEDIRNAME);
 #endif
 	// any set gamedirs will be freed up to here
@@ -1512,6 +1506,7 @@
 	
 #ifdef __unix__
 	/* Create directory if it does not exist. */
+	FS_CreatePath(fs_gamedir);
 	Sys_Mkdir(fs_gamedir);
 	
 	Com_Printf("Using '%s' for writing.\n", fs_gamedir);
@@ -1624,11 +1619,14 @@
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
 		if (fs_cddir->string[0])
 			FS_AddGameDirectory (va("%s/%s", fs_cddir->string, dir) );
+#ifdef DATADIR
+		FS_AddGameDirectory(va("%s/%s", DATADIR, dir));
+#endif
 #ifdef LIBDIR
 		FS_AddGameDirectory(va("%s/%s", LIBDIR, dir));
 #endif
 		FS_AddGameDirectory (va("%s/%s", fs_basedir->string, dir) );
-#if defined(DATADIR) && !defined(_WIN32)	
+#ifdef DATADIR
 		FS_AddHomeAsGameDirectory(dir);
 #endif
 	}
@@ -1799,6 +1797,159 @@
 	return (list);
 }
 #endif
+
+/*
+ * CompareAttributesPack
+ *
+ * Compare file attributes (musthave and canthave) in packed files. If
+ * "output" is not NULL, "size" is greater than zero and the file matches the
+ * attributes then a copy of the matching string will be placed there (with
+ * SFF_SUBDIR it changes).
+ *
+ * Returns a boolean value, true if the attributes match the file.
+ */
+qboolean
+ComparePackFiles(const char *findname, const char *name,
+    unsigned musthave, unsigned canthave, char *output, int size)
+{
+	qboolean	 retval;
+	char		*ptr;
+	char		 buffer[MAX_OSPATH];
+
+	Q_strncpyz(buffer, name, sizeof(buffer));
+
+	if ((canthave & SFF_SUBDIR) && name[strlen(name)-1] == '/')
+		return (false);
+
+	if (musthave & SFF_SUBDIR) {
+		if ((ptr = strrchr(buffer, '/')) != NULL)
+			*ptr = '\0';
+		else
+			return (false);
+	}
+
+	if ((musthave & SFF_HIDDEN) || (canthave & SFF_HIDDEN)) {
+		if ((ptr = strrchr(buffer, '/')) == NULL)
+			ptr = buffer;
+		if (((musthave & SFF_HIDDEN) && ptr[1] != '.') ||
+		    ((canthave & SFF_HIDDEN) && ptr[1] == '.'))
+			return (false);
+	}
+
+	if (canthave & SFF_RDONLY)
+		return (false);
+
+	retval = glob_match((char *)findname, buffer);
+
+	if (retval && output != NULL)
+		Q_strncpyz(output, buffer, size);
+
+	return (retval);
+}
+
+/*
+ * FS_ListFiles2
+ *
+ * Create a list of files that match a criteria.
+ *
+ * Searchs are relative to the game directory and use all the search paths
+ * including .pak and .pk3 files.
+ */
+char **
+FS_ListFiles2(char *findname, int *numfiles, unsigned musthave, unsigned canthave)
+{
+	fsSearchPath_t	*search;		/* Search path. */
+	int		i, j;			/* Loop counters. */
+	int		nfiles;			/* Number of files found. */
+	int		tmpnfiles;		/* Temp number of files. */
+	char		**tmplist;		/* Temporary list of files. */
+	char		**list;			/* List of files found. */
+	char		path[MAX_OSPATH];	/* Temporary path. */
+
+	nfiles = 0;
+	list = malloc(sizeof(char *));
+
+	for (search = fs_searchPaths; search != NULL; search = search->next) {
+		if (search->pack != NULL) {
+			if (canthave & SFF_INPACK)
+				continue;
+
+			for (i = 0, j = 0; i < search->pack->numFiles; i++)
+				if (ComparePackFiles(findname,
+				    search->pack->files[i].name,
+				    musthave, canthave, NULL, 0))
+					j++;
+			if (j == 0)
+				continue;
+			nfiles += j;
+			list = realloc(list, nfiles * sizeof(char *));
+			for (i = 0, j = nfiles - j;
+			    i < search->pack->numFiles;
+			    i++)
+				if (ComparePackFiles(findname,
+				    search->pack->files[i].name,
+				    musthave, canthave, path, sizeof(path)))
+					list[j++] = strdup(path);
+		} else if (search->path != NULL) {
+			if (musthave & SFF_INPACK)
+				continue;
+
+			Com_sprintf(path, sizeof(path), "%s/%s",
+			    search->path, findname);
+			tmplist = FS_ListFiles(path, &tmpnfiles, musthave,
+			    canthave);
+			if (tmplist != NULL) {
+				tmpnfiles--;
+				nfiles += tmpnfiles;
+				list = realloc(list, nfiles * sizeof(char *));
+				for (i = 0, j = nfiles - tmpnfiles;
+				    i < tmpnfiles;
+				    i++, j++)
+					list[j] = strdup(tmplist[i] +
+					    strlen(search->path) + 1);
+				FS_FreeList(tmplist, tmpnfiles + 1);
+			}
+		}
+	}
+
+	/* Delete duplicates. */
+	tmpnfiles = 0;
+	for (i = 0; i < nfiles; i++) {
+		if (list[i] == NULL)
+			continue;
+		for (j = i + 1; j < nfiles; j++)
+			if (list[j] != NULL &&
+			    strcmp(list[i], list[j]) == 0) {
+				free(list[j]);
+				list[j] = NULL;
+				tmpnfiles++;
+			}
+	}
+
+	if (tmpnfiles > 0) {
+		nfiles -= tmpnfiles;
+		tmplist = malloc(nfiles * sizeof(char *));
+		for (i = 0, j = 0; i < nfiles + tmpnfiles; i++)
+			if (list[i] != NULL)
+				tmplist[j++] = list[i];
+		free(list);
+		list = tmplist;
+	}
+
+	/* Add a guard. */
+	if (nfiles > 0) {
+		nfiles++;
+		list = realloc(list, nfiles * sizeof(char *));
+		list[nfiles - 1] = NULL;
+	} else {
+		free(list);
+		list = NULL;
+	}
+
+	*numfiles = nfiles;
+
+	return (list);
+}
 
 /*
 ================
