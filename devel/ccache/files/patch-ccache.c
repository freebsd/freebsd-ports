--- ccache.c.orig	2004/09/13 10:19:06	1.96
+++ ccache.c	2005/11/24 21:54:09	1.98
@@ -331,8 +331,12 @@
 		hash_string(str_basename(args->argv[0]));
 	}
 
-	hash_int(st.st_size);
-	hash_int(st.st_mtime);
+	if (getenv("CCACHE_HASH_COMPILER")) {
+		hash_file(args->argv[0]);
+	} else if (!getenv("CCACHE_NOHASH_SIZE_MTIME")) {
+		hash_int(st.st_size);
+		hash_int(st.st_mtime);
+	}
 
 	/* possibly hash the current working directory */
 	if (getenv("CCACHE_HASHDIR")) {
