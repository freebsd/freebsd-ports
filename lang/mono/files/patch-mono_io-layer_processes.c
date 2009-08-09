
$FreeBSD$

--- mono/io-layer/processes.c.orig
+++ mono/io-layer/processes.c
@@ -1950,7 +1950,7 @@
 	{
 		mods = load_modules ();
 #else
-	filename = g_strdup_printf ("/proc/%d/maps", pid);
+	filename = g_strdup_printf ("/proc/%d/map", pid);
 	if ((fp = fopen (filename, "r")) == NULL) {
 		/* No /proc/<pid>/maps so just return the main module
 		 * shortcut for now
@@ -2111,7 +2111,7 @@
 	{
 		mods = load_modules ();
 #else
-	filename = g_strdup_printf ("/proc/%d/maps", pid);
+	filename = g_strdup_printf ("/proc/%d/map", pid);
 	if ((fp = fopen (filename, "r")) == NULL) {
 		if (errno == EACCES && module == NULL && base == TRUE) {
 			procname_ext = get_process_name_from_proc (pid);
@@ -2266,7 +2266,7 @@
 		mods = load_modules ();
 #else
 	/* Look up the address in /proc/<pid>/maps */
-	filename = g_strdup_printf ("/proc/%d/maps", pid);
+	filename = g_strdup_printf ("/proc/%d/map", pid);
 	if ((fp = fopen (filename, "r")) == NULL) {
 		/* No /proc/<pid>/maps, so just return failure
 		 * for now
