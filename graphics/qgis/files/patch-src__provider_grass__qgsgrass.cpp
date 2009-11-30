--- src/providers/grass/qgsgrass.cpp
+++ src/providers/grass/qgsgrass.cpp
@@ -335,10 +335,10 @@
 // #if defined(WIN32)
 //  G__setenv(( char * ) "GISDBASE", shortPath( gisdbase ).toLocal8Bit().data() );
 //#else
-  G__setenv(( char * ) "GISDBASE", gisdbase.toAscii().constData() );
+  G__setenv( "GISDBASE", gisdbase.toAscii().data() );
 //#endif
-  G__setenv(( char * ) "LOCATION_NAME", location.toAscii().constData() );
-  G__setenv(( char * ) "MAPSET", ( char * ) "PERMANENT" ); // PERMANENT must always exist
+  G__setenv( "LOCATION_NAME", location.toAscii().data() );
+  G__setenv( "MAPSET", "PERMANENT" ); // PERMANENT must always exist
 
   // Add all available mapsets to search path
   char **ms = G_available_mapsets();
@@ -354,10 +354,10 @@
 // #if defined(WIN32)
 //  G__setenv(( char * ) "GISDBASE", shortPath( gisdbase ).toUtf8().data() );
 // #else
-  G__setenv(( char * ) "GISDBASE", gisdbase.toUtf8().data() );
+  G__setenv( "GISDBASE", gisdbase.toUtf8().data() );
 // #endif
-  G__setenv(( char * ) "LOCATION_NAME", location.toUtf8().data() );
-  G__setenv(( char * ) "MAPSET", mapset.toUtf8().data() );
+  G__setenv( "LOCATION_NAME", location.toUtf8().data() );
+  G__setenv( "MAPSET", mapset.toUtf8().data() );
 
   // Add all available mapsets to search path
   char **ms = G_available_mapsets();
@@ -551,14 +551,14 @@
   putenv( gisrcEnvChar );
 
   // Reinitialize GRASS
-  G__setenv(( char * ) "GISRC", gisrcEnv.toUtf8().data() );
+  G__setenv( "GISRC", gisrcEnv.toUtf8().data() );
 #if defined(WIN32)
-  G__setenv(( char * ) "GISDBASE", shortPath( gisdbase ).toLocal8Bit().data() );
+  G__setenv( "GISDBASE", shortPath( gisdbase ).toLocal8Bit().data() );
 #else
-  G__setenv(( char * ) "GISDBASE", gisdbase.toUtf8().data() );
+  G__setenv( "GISDBASE", gisdbase.toUtf8().data() );
 #endif
-  G__setenv(( char * ) "LOCATION_NAME", location.toLocal8Bit().data() );
-  G__setenv(( char * ) "MAPSET", mapset.toLocal8Bit().data() );
+  G__setenv( "LOCATION_NAME", location.toLocal8Bit().data() );
+  G__setenv( "MAPSET", mapset.toLocal8Bit().data() );
   defaultGisdbase = gisdbase;
   defaultLocation = location;
   defaultMapset = mapset;
@@ -590,13 +590,13 @@
     }
     mMapsetLock = "";
 
-    putenv(( char * ) "GISRC" );
+    putenv( "GISRC" );
 
     // Reinitialize GRASS
-    G__setenv(( char * ) "GISRC", ( char * ) "" );
-    G__setenv(( char * ) "GISDBASE", ( char * ) "" );
-    G__setenv(( char * ) "LOCATION_NAME", ( char * ) "" );
-    G__setenv(( char * ) "MAPSET", ( char * ) "" );
+    G__setenv( "GISRC", "" );
+    G__setenv( "GISDBASE", "" );
+    G__setenv( "LOCATION_NAME", "" );
+    G__setenv( "MAPSET", "" );
     defaultGisdbase = "";
     defaultLocation = "";
     defaultMapset = "";
@@ -870,7 +870,7 @@
 {
   QgsGrass::setLocation( gisbase, location );
 
-  if ( G__get_window( window, ( char * ) "", ( char * ) "WIND", mapset.toUtf8().data() ) )
+  if ( G__get_window( window, "", "WIND", mapset.toUtf8().data() ) )
   {
     return false;
   }
@@ -1003,7 +1003,7 @@
   }
   else if ( type == Region )
   {
-    if ( G__get_window( window, ( char * ) "windows",
+    if ( G__get_window( window, "windows",
                         map.toUtf8().data(),
                         mapset.toUtf8().data() ) != NULL )
     {
