
$FreeBSD$

--- src/main.c.orig	Tue Mar  2 21:31:52 2004
+++ src/main.c	Tue Mar  2 21:32:16 2004
@@ -106,7 +106,7 @@
                 /* new set? */
                 if ( strequal( "<CREATE SET>", levelset_home_names[config.levelset_home_id] ) ) {
                     editor_file = calloc( 16, sizeof( char ) );
-                    sprintf( path, "%s/%s/lbreakout2-levels", getenv( "HOME" ), CONFIG_DIR_NAME );
+                    snprintf( path, sizeof(path), "%s/%s/lbreakout2-levels", getenv( "HOME" ), CONFIG_DIR_NAME );
                     if ( !enter_string( font, "Set Name:", editor_file, 12 ) || !file_check( path, editor_file, "w" ) ) {
                         free( editor_file );
                         break;
