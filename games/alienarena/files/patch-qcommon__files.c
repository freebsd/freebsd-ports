--- ./qcommon/files.c.orig	Tue Dec 11 18:57:14 2007
+++ ./qcommon/files.c	Tue Dec 11 21:51:48 2007
@@ -734,6 +734,12 @@
 	else
 	{
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
+#ifdef DATADIR
+		FS_AddGameDirectory (va("%s/%s", DATADIR, dir) );
+#endif
+#ifdef LIBDIR
+		FS_AddGameDirectory (va("%s/%s", LIBDIR, dir) );
+#endif
 		FS_AddGameDirectory (va("%s/%s", fs_basedir->string, dir) );
 #ifdef __unix__
 		FS_AddHomeAsGameDirectory(dir);
@@ -834,7 +840,156 @@
 	return list;
 }
 
-//#ifdef __unix__
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
+	strncpy(buffer, name, sizeof(buffer)-1);
+	buffer[sizeof(buffer)-1] = '\0';
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
+	if (retval && output != NULL) {
+		strncpy(output, buffer, size-1);
+		buffer[size-1] = '\0';
+	}
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
+	searchpath_t	*search;		/* Search path. */
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
+	for (search = fs_searchpaths; search != NULL; search = search->next) {
+		if (search->pack != NULL) {
+			for (i = 0, j = 0; i < search->pack->numfiles; i++)
+				if (ComparePackFiles(findname,
+				    search->pack->files[i].name,
+				    musthave, canthave, NULL, 0))
+					j++;
+			if (j == 0)
+				continue;
+			nfiles += j;
+			list = realloc(list, nfiles * sizeof(char *));
+			for (i = 0, j = nfiles - j;
+			    i < search->pack->numfiles;
+			    i++)
+				if (ComparePackFiles(findname,
+				    search->pack->files[i].name,
+				    musthave, canthave, path, sizeof(path)))
+					list[j++] = strdup(path);
+		} else if (search->filename != NULL) {
+			Com_sprintf(path, sizeof(path), "%s/%s",
+			    search->filename, findname);
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
+					    strlen(search->filename) + 1);
+				FS_FreeFileList(tmplist, tmpnfiles);
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
+
 void FS_FreeFileList (char **list, int n) // jit
 {
 	int i;
@@ -850,7 +1005,6 @@
 
 	free(list);
 }
-//#endif
 
 /*
 ** FS_Dir_f
@@ -976,6 +1130,19 @@
 	Cmd_AddCommand ("path", FS_Path_f);
 	Cmd_AddCommand ("link", FS_Link_f);
 	Cmd_AddCommand ("dir", FS_Dir_f );
+
+	//
+	// DATADIR / LIBDIR support.
+	// Both directories are used to load data and libraries from, allowing
+	// different OSes to have them where they want, according to their
+	// conventions.
+	//
+#ifdef DATADIR
+	FS_AddGameDirectory (va("%s/"BASEDIRNAME, DATADIR));
+#endif
+#ifdef LIBDIR
+	FS_AddGameDirectory (va("%s/"BASEDIRNAME, LIBDIR));
+#endif
 
 	//
 	// basedir <path>
