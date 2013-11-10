--- sound/aosound.c.orig	2013-05-16 22:26:12.000000000 +0200
+++ sound/aosound.c	2013-11-09 22:31:16.000000000 +0100
@@ -78,14 +78,14 @@
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
 
@@ -119,6 +119,7 @@
   }
 
   free( mutable );
+  return 0;
 }
 
 int
