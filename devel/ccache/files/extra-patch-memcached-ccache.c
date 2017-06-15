--- ccache.c.orig	2017-03-09 09:08:38.803365000 -0800
+++ ccache.c	2017-03-09 09:08:42.059821000 -0800
@@ -2153,7 +2153,7 @@ calculate_object_hash(struct args *args,
 			conf->direct_mode = false;
 			return NULL;
 		}
-		char *manifest_name = hash_result(hash);
+		manifest_name = hash_result(hash);
 		manifest_path = get_path_in_cache(manifest_name, ".manifest");
 		/* Check if the manifest file is there. */
 		struct stat st;
