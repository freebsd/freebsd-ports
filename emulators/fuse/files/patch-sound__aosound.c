--- sound/aosound.c.orig	2013-05-16 20:26:12 UTC
+++ sound/aosound.c
@@ -78,14 +78,14 @@ driver_error( void )
   }
 }
 
-static void
+static int
 parse_driver_options( const char *device, int *driver_id, ao_option **options )
 {
   char *mutable, *option, *key, *value;
 
   /* Get a copy of the device string we can modify */
   if( !device || *device == '\0' )
-    return;
+    return 0;
 
   mutable = utils_safe_strdup( device );
 
@@ -119,6 +119,7 @@ parse_driver_options( const char *device
   }
 
   free( mutable );
+  return 0;
 }
 
 int
