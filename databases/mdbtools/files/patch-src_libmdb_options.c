--- src/libmdb/options.c.orig	2020-12-17 19:03:05 UTC
+++ src/libmdb/options.c
@@ -50,9 +50,12 @@ load_options()
 {
 	char *opt;
 	char *s;
-    char *ctx;
+	char *ctx;
 
-    if (!optset && (s=getenv("MDBOPTS"))) {
+	if (optset)
+		return;
+
+	if ((s=getenv("MDBOPTS"))) {
 		opt = strtok_r(s, ":", &ctx);
 		while (opt) {
         	if (!strcmp(opt, "use_index")) opts |= MDB_USE_INDEX;
@@ -74,6 +77,9 @@ load_options()
 			opt = strtok_r(NULL,":", &ctx);
 		}
     }
+#ifdef HAVE_LIBMSWSTR
+	opts |= MDB_USE_INDEX;
+#endif
 	optset = 1;
 }
 int
