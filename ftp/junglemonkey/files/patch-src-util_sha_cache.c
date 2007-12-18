--- src/util/sha_cache.c.orig	2007-12-17 23:04:06.000000000 +0100
+++ src/util/sha_cache.c	2007-12-17 23:09:16.000000000 +0100
@@ -213,7 +213,7 @@
   g_return_if_fail (sha_cache);
   g_return_if_fail (file);
 
-  g_hash_table_foreach (sha_cache->path_to_sha, write_hfunc, file);
+  if(sha_cache) g_hash_table_foreach (sha_cache->path_to_sha, write_hfunc, file);
 }
 
 
