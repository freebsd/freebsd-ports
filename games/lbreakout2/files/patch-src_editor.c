
$FreeBSD$

--- src/editor.c.orig	Tue Mar  2 21:26:03 2004
+++ src/editor.c	Tue Mar  2 21:27:00 2004
@@ -725,7 +725,7 @@
 {
     FILE *file = 0;
     /* set full file name */
-    sprintf( edit_file_name, "%s/%s/lbreakout2-levels/%s", (getenv( "HOME" )?getenv( "HOME" ):"."), CONFIG_DIR_NAME, file_name );
+    snprintf( edit_file_name, sizeof(edit_file_name), "%s/%s/lbreakout2-levels/%s", (getenv( "HOME" )?getenv( "HOME" ):"."), CONFIG_DIR_NAME, file_name );
     /* test this file for write access. use append to keep contents */
     if ( ( file = fopen( edit_file_name, "a" ) ) == 0 ) {
         fprintf( stderr, "Permission to write to file '%s' denied.\n", edit_file_name );
