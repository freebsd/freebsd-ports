
$FreeBSD$

--- src/manager.c.orig	Tue Mar  2 21:29:21 2004
+++ src/manager.c	Tue Mar  2 21:29:40 2004
@@ -126,7 +126,7 @@
         return;
     }
     /* get file name + path */
-    sprintf( fname, "%s/%s/lbreakout2-levels/%s", getenv( "HOME" ), CONFIG_DIR_NAME, levelset_home_names[config.levelset_home_id] );
+    snprintf( fname, sizeof(fname), "%s/%s/lbreakout2-levels/%s", getenv( "HOME" ), CONFIG_DIR_NAME, levelset_home_names[config.levelset_home_id] );
     remove( fname );
     levelsets_load_names(); /* reinit name lists and configs indices */
     /* reassign these name lists as position in memory has changed */
