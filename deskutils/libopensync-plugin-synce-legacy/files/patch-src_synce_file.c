--- src/synce_file.c.orig	2007-03-27 22:14:24.000000000 +1000
+++ src/synce_file.c	2008-12-27 23:47:34.000000000 +0900
@@ -114,7 +114,7 @@
                   size = CeGetFileSize(h, NULL);
                   CeCloseHandle(h);
                 } else size = 0;
-                hash = g_strdup_printf("%ld-%u", ff->last_mod, size);
+                hash = g_strdup_printf("%ld-%u", (long)ff->last_mod, size);
 		osync_change_set_hash(change, hash);
                 fprintf(stderr, "%s(%s) hash %s\n", __func__, path, hash);
                 g_free(hash);
