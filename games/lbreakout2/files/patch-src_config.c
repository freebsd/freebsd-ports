
$FreeBSD$

--- src/config.c.orig	Tue Mar  2 21:29:55 2004
+++ src/config.c	Tue Mar  2 21:30:24 2004
@@ -40,7 +40,7 @@
 void config_check_dir()
 {
     char level_dir[512];
-    sprintf( config.dir_name, "%s/%s", (getenv( "HOME" )?getenv( "HOME" ):"."), CONFIG_DIR_NAME );
+    snprintf( config.dir_name, sizeof(config.dir_name), "%s/%s", (getenv( "HOME" )?getenv( "HOME" ):"."), CONFIG_DIR_NAME );
     /* test and create .lgames */
     if ( opendir( config.dir_name ) == 0 ) {
         fprintf( stderr, "couldn't find/open config directory '%s'\n", config.dir_name );
