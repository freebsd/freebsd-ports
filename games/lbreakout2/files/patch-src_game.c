
$FreeBSD$

--- src/game.c.orig	Tue Mar  2 21:30:46 2004
+++ src/game.c	Tue Mar  2 21:31:02 2004
@@ -561,7 +561,7 @@
     /* load level */
     setname = levelset_names[config.levelset_id];
     if ( levelset_names[config.levelset_id][0] == '~' ) {
-        sprintf( path, "%s/%s/lbreakout2-levels", (getenv( "HOME" )?getenv( "HOME" ):"."), CONFIG_DIR_NAME );
+        snprintf( path, sizeof(path), "%s/%s/lbreakout2-levels", (getenv( "HOME" )?getenv( "HOME" ):"."), CONFIG_DIR_NAME );
         setname++;
     }
     else
