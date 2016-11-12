--- src/physfs.c.orig	2016-10-25 15:49:32 UTC
+++ src/physfs.c
@@ -331,7 +331,6 @@ void physfs_reset_dir_allowed(lua_State 
 	}
 	nb_allowed_dirs = 0;
 	can_set_allowed_dirs = TRUE;
-	return 0;
 }
 
 static int lua_fs_done_dir_allowed(lua_State *L) {
