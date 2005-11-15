--- ccache.c.orig	Mon Sep 13 06:38:30 2004
+++ ccache.c	Tue Nov 15 14:59:46 2005
@@ -331,8 +331,10 @@
 		hash_string(str_basename(args->argv[0]));
 	}
 
-	hash_int(st.st_size);
-	hash_int(st.st_mtime);
+	if (!getenv("CCACHE_NOHASH_SIZE_MTIME")) {
+		hash_int(st.st_size);
+		hash_int(st.st_mtime);
+	}
 
 	/* possibly hash the current working directory */
 	if (getenv("CCACHE_HASHDIR")) {
