--- ./main.c.orig	2012-07-26 04:13:43.000000000 +0200
+++ ./main.c	2012-07-29 11:31:53.000000000 +0200
@@ -26,28 +26,18 @@
 
 static unsigned int global_traverse_flags = PKGF_NONE;
 
-static int want_help = 0;
-static int want_version = 0;
 static int want_cflags = 0;
 static int want_libs = 0;
 static int want_modversion = 0;
-static int want_static = 0;
 static int want_requires = 0;
 static int want_requires_private = 0;
 static int want_variables = 0;
 static int want_digraph = 0;
-static int want_env_only = 0;
 static int want_uninstalled = 0;
-static int want_no_uninstalled = 0;
 static int want_keep_system_cflags = 0;
 static int want_keep_system_libs = 0;
-static int want_ignore_conflicts = 0;
 static int maximum_traverse_depth = -1;
 
-static char *required_pkgconfig_version = NULL;
-static char *required_exact_module_version = NULL;
-static char *required_max_module_version = NULL;
-static char *required_module_version = NULL;
 static char *want_variable = NULL;
 static char *sysroot_dir = NULL;
 
@@ -101,6 +91,15 @@
 }
 
 static void
+print_list_entry(const pkg_t *entry)
+{
+	if (entry->uninstalled)
+		return;
+
+	printf("%-30s %s - %s\n", entry->id, entry->realname, entry->description);
+}
+
+static void
 print_cflags(pkg_fragment_t *list)
 {
 	pkg_fragment_t *frag;
@@ -414,6 +413,12 @@
 static void
 version(void)
 {
+	printf("%s\n", PKG_PKGCONFIG_VERSION_EQUIV);
+}
+
+static void
+about(void)
+{
 	printf("%s %s%s\n", PACKAGE_NAME, PACKAGE_VERSION, HAVE_STRICT_MODE ? " [strict]" : " [pkg-config compatible]");
 	printf("Copyright (c) 2011 - 2012 pkgconf authors (see AUTHORS in documentation directory).\n\n");
 	printf("Permission to use, copy, modify, and/or distribute this software for any\n");
@@ -438,6 +443,7 @@
 	printf("                                    with a specified pkg-config version\n");
 	printf("  --errors-to-stdout                print all errors on stdout instead of stderr\n");
 	printf("  --silence-errors                  explicitly be silent about errors\n");
+	printf("  --list-all                        list all known packages\n");
 
 	printf("\nchecking specific pkg-config database entries:\n\n");
 
@@ -482,6 +488,11 @@
 	pkg_queue_t *pkgq = NULL;
 	pkg_queue_t *pkgq_head = NULL;
 	char *builddir;
+	char *required_pkgconfig_version = NULL;
+	char *required_exact_module_version = NULL;
+	char *required_max_module_version = NULL;
+	char *required_module_version = NULL;
+	int want_env_only = 0;
 	int want_errors_on_stdout = 0;
 	int want_silence_errors = 0;
 	int want_libs_L = 0;
@@ -489,9 +500,17 @@
 	int want_libs_other = 0;
 	int want_cflags_I = 0;
 	int want_cflags_other = 0;
+	int want_list = 0;
+	int want_about = 0;
+	int want_help = 0;
+	int want_version = 0;
+	int want_ignore_conflicts = 0;
+	int want_static = 0;
+	int want_no_uninstalled = 0;
 
 	struct pkg_option options[] = {
 		{ "version", no_argument, &want_version, 1, },
+		{ "about", no_argument, &want_about, 1, },
 		{ "atleast-version", required_argument, NULL, 2, },
 		{ "atleast-pkgconfig-version", required_argument, NULL, 3, },
 		{ "libs", no_argument, &want_libs, 4, },
@@ -524,6 +543,7 @@
 		{ "ignore-conflicts", no_argument, &want_ignore_conflicts, 30, },
 		{ "errors-to-stdout", no_argument, &want_errors_on_stdout, 31, },
 		{ "silence-errors", no_argument, &want_silence_errors, 32, },
+		{ "list-all", no_argument, &want_list, 33, },
 		{ NULL, 0, NULL, 0 }
 	};
 
@@ -573,6 +593,12 @@
 	else if (want_cflags_other)
 		want_cflags = want_cflags_other;
 
+	if (want_about)
+	{
+		about();
+		return EXIT_SUCCESS;
+	}
+
 	if (want_version)
 	{
 		version();
@@ -627,6 +653,12 @@
 		return EXIT_FAILURE;
 	}
 
+	if (want_list)
+	{
+		pkg_scan_all(print_list_entry);
+		return EXIT_SUCCESS;
+	}
+
 	if (required_module_version != NULL)
 	{
 		pkg_t *pkg;
