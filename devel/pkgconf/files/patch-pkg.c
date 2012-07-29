--- ./pkg.c.orig	2012-07-29 11:35:32.856917000 +0200
+++ ./pkg.c	2012-07-29 11:31:53.000000000 +0200
@@ -142,11 +142,18 @@
 {
 	pkg_t *pkg;
 	char readbuf[PKG_BUFSIZE];
+	char *idptr;
 
 	pkg = calloc(sizeof(pkg_t), 1);
 	pkg->filename = strdup(filename);
 	pkg->vars = pkg_tuple_add(pkg->vars, "pcfiledir", pkg_get_parent_dir(pkg));
 
+	/* make module id */
+	pkg->id = strdup(basename(pkg->filename));
+	idptr = strrchr(pkg->id, '.');
+	if (idptr)
+		*idptr = '\0';
+
 	while (pkg_fgetline(readbuf, PKG_BUFSIZE, f) != NULL)
 	{
 		char op, *p, *key = NULL, *value = NULL;
@@ -274,6 +281,79 @@
 	return pkg;
 }
 
+static void
+pkg_scan_dir(const char *path, pkg_iteration_func_t func)
+{
+	DIR *dir;
+	struct dirent *dirent;
+
+	dir = opendir(path);
+	if (dir == NULL)
+		return;
+
+	for (dirent = readdir(dir); dirent != NULL; dirent = readdir(dir))
+	{
+		static char filebuf[PKG_BUFSIZE];
+		pkg_t *pkg;
+		FILE *f;
+		struct stat st;
+
+		strlcpy(filebuf, path, sizeof filebuf);
+		strlcat(filebuf, "/", sizeof filebuf);
+		strlcat(filebuf, dirent->d_name, sizeof filebuf);
+
+		stat(filebuf, &st);
+		if (!(S_ISREG(st.st_mode)))
+			continue;
+
+		f = fopen(filebuf, "r");
+		if (f == NULL)
+			continue;
+
+		pkg = pkg_new_from_file(filebuf, f);
+		if (pkg != NULL)
+		{
+			func(pkg);
+			pkg_free(pkg);
+		}
+	}
+
+	closedir(dir);
+}
+
+void
+pkg_scan(const char *search_path, pkg_iteration_func_t func)
+{
+	char **path = NULL;
+	size_t count = 0, iter = 0;
+
+	/* PKG_CONFIG_PATH has to take precedence */
+	if (search_path == NULL)
+		return;
+
+	count = path_split(search_path, &path);
+
+	for (iter = 0; iter < count; iter++)
+		pkg_scan_dir(path[iter], func);
+
+	path_free(path, count);
+}
+
+void
+pkg_scan_all(pkg_iteration_func_t func)
+{
+	char *path;
+
+	path = getenv("PKG_CONFIG_PATH");
+	if (path)
+	{
+		pkg_scan(path, func);
+		return;
+	}
+
+	pkg_scan(get_pkgconfig_path(), func);
+}
+
 #ifdef _WIN32
 pkg_t *
 pkg_find_in_registry_key(HKEY hkey, const char *name, unsigned int flags)
