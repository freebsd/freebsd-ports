
$FreeBSD$

--- src/levels.c.orig	Tue Mar  2 21:31:19 2004
+++ src/levels.c	Tue Mar  2 21:31:36 2004
@@ -220,7 +220,7 @@
     /* create dynamic list */
     names = list_create( LIST_NO_AUTO_DELETE, NO_CALLBACK );
     /* parse home directory */
-    sprintf( level_dir, "%s/%s/lbreakout2-levels", (getenv( "HOME" )?getenv( "HOME" ):"."), CONFIG_DIR_NAME );
+    snprintf( level_dir, sizeof(level_dir), "%s/%s/lbreakout2-levels", (getenv( "HOME" )?getenv( "HOME" ):"."), CONFIG_DIR_NAME );
     text = get_file_list( level_dir, 0, level_dir );
     for ( i = 0; i < text->count; i++ ) {
         /* filter stuff */
