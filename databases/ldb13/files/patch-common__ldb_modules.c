--- common/ldb_modules.c.orig	2018-02-14 01:18:43 UTC
+++ common/ldb_modules.c
@@ -1103,7 +1103,7 @@ static int ldb_modules_load_dir(const ch
 */
 void ldb_set_modules_dir(struct ldb_context *ldb, const char *path)
 {
-	int ret = ldb_modules_load_path(path, LDB_VERSION);
+	int ret = ldb_modules_load_dir(path, LDB_VERSION);
 	if (ret != LDB_SUCCESS) {
 		ldb_asprintf_errstring(ldb, "Failed to load modules from: %s\n", path);
 	}
