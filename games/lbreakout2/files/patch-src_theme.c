
$FreeBSD$

--- src/theme.c.orig	Tue Mar  2 21:27:06 2004
+++ src/theme.c	Tue Mar  2 21:29:01 2004
@@ -115,7 +115,7 @@
 {
     SDL_Surface *surf = 0;
     char path[512];
-    sprintf( path, "%s/.lgames/lbreakout2-themes/%s/%s", getenv( "HOME" ), theme_name, name );
+    snprintf( path, sizeof(path), "%s/.lgames/lbreakout2-themes/%s/%s", getenv( "HOME" ), theme_name, name );
     if ( strequal( theme_name, "Default" ) || ( surf = load_surf( path, SDL_SWSURFACE | SDL_NONFATAL ) ) == 0 )
         surf = load_surf( name, SDL_SWSURFACE );
     return surf;
@@ -125,7 +125,7 @@
 {
     Sound_Chunk *sound = 0;
     char path[512];
-    sprintf( path, "%s/.lgames/lbreakout2-themes/%s/%s", getenv( "HOME" ), theme_name, name );
+    snprintf( path, sizeof(path), "%s/.lgames/lbreakout2-themes/%s/%s", getenv( "HOME" ), theme_name, name );
     if ( strequal( theme_name, "Default" ) ||  ( sound = sound_chunk_load( path ) ) == 0 )
         sound = sound_chunk_load( name );
     return sound;
@@ -135,7 +135,7 @@
 {
     Font *font = 0;
     char path[512];
-    sprintf( path, "%s/.lgames/lbreakout2-themes/%s/%s", getenv( "HOME" ), theme_name, name );
+    snprintf( path, sizeof(path), "%s/.lgames/lbreakout2-themes/%s/%s", getenv( "HOME" ), theme_name, name );
     if ( strequal( theme_name, "Default" ) ||  ( font = load_fixed_font( path, start, len, width, SDL_SWSURFACE | SDL_NONFATAL ) ) == 0 )
         font = load_fixed_font( name, start, len, width, SDL_SWSURFACE );
     return font;
@@ -201,7 +201,7 @@
     struct stat filestat;
     char path[512];
     char fname[512];
-    sprintf( fname, "%s/.lgames/lbreakout2-themes/%s/back0.png", getenv( "HOME" ), theme_name );
+    snprintf( fname, sizeof(path), "%s/.lgames/lbreakout2-themes/%s/back0.png", getenv( "HOME" ), theme_name );
     if ( strequal( theme_name, "Default" ) || stat( fname, &filestat ) == -1 ) {
         /* use original backs */
         bkgnd_count = BACK_COUNT;
@@ -209,7 +209,7 @@
     }
     else {
         /* use new backs */
-        sprintf( path, "%s/.lgames/lbreakout2-themes/%s", getenv( "HOME" ), theme_name );
+        snprintf( path, sizeof(path), "%s/.lgames/lbreakout2-themes/%s", getenv( "HOME" ), theme_name );
         bkgnd_count = -1;
         do {
             bkgnd_count++;
@@ -248,7 +248,7 @@
     /* auxilary list */
     list = list_create( LIST_NO_AUTO_DELETE, NO_CALLBACK );
     /* theme directory */
-    sprintf( dir, "%s/.lgames/lbreakout2-themes", getenv( "HOME" ) );
+    snprintf( dir, sizeof(dir), "%s/.lgames/lbreakout2-themes", getenv( "HOME" ) );
     if ( ( hdir = opendir( dir ) ) != 0 ) {
         while ( ( entry = readdir( hdir ) ) ) {
             if ( entry->d_name[0] == '.' ) 
