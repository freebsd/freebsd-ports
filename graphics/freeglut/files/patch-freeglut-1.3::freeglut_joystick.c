--- freeglut-1.3/freeglut_joystick.c.orig	Wed Jan 12 07:49:08 2000
+++ freeglut-1.3/freeglut_joystick.c	Sun May  4 17:16:24 2003
@@ -32,23 +32,23 @@
  * PWO: this is not exactly what Steve Baker has done for PLIB, as I had to convert
  *      it from C++ to C. And I've also reformatted it a bit (that's my little
  *      personal deviation :]) I don't really know if it is still portable...
- *      Steve: could you please add some comments to the code? :)
+ *      Steve: could you please add some comments to the code? :)
  *
- * FreeBSD port - courtesy of Stephen Montgomery-Smith <stephen@math.missouri.edu>
+ * FreeBSD port - courtesy of Stephen Montgomery-Smith <stephen@math.missouri.edu>
  */
 
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
-
-#define G_LOG_DOMAIN "freeglut-joystick"
+
+#define G_LOG_DOMAIN "freeglut-joystick"
 
 #include "../include/GL/freeglut.h"
 #include "../include/GL/freeglut_internal.h"
-
-/*
- * PWO: I don't like it at all. It's a mess. Could it be cleared?
- */
+
+/*
+ * PWO: I don't like it at all. It's a mess. Could it be cleared?
+ */
 #ifdef WIN32
 #   include <windows.h>
 #   if defined( __CYGWIN32__ ) || defined( __CYGWIN__ )
@@ -61,7 +61,7 @@
 #   include <unistd.h>
 #   include <fcntl.h>
 #   ifdef __FreeBSD__
-#       include <machine/joystick.h>
+#       include <sys/joystick.h>
 #       define JS_DATA_TYPE joystick
 #       define JS_RETURN (sizeof(struct JS_DATA_TYPE))
 #   elif defined(__linux__)
@@ -126,7 +126,7 @@
         gint        tmp_buttons;
         float       tmp_axes[ _JS_MAX_AXES ];
 #   else
-        JS_DATA_TYPE js;
+        struct JS_DATA_TYPE js;
 #   endif
 
     gchar fname[ 128 ];
@@ -251,7 +251,7 @@
 
     if( status != JS_RETURN )
     {
-        g_warning( fname );
+        g_warning( joy->fname );
         joy->error = TRUE;
         return;
     }
@@ -409,12 +409,12 @@
         return;
 
 #   ifdef __FreeBSD__
-    fghJoystickRawRead( buttons, axes );
+    fghJoystickRawRead(joy, buttons, axes );
     joy->error = axes[ 0 ] < -1000000000.0f;
     if( joy->error )
       return ;
 
-    sprintf( joyfname, "%s/.joy%drc", g_getenv( "HOME" ), id );
+    sprintf( joyfname, "%s/.joy%drc", g_getenv( "HOME" ), joy->id );
 
     joyfile = fopen( joyfname, "r" );
     joy->error = (joyfile == NULL);
@@ -435,8 +435,8 @@
 
     for( i=0 ; i<_JS_MAX_AXES ; i++ )
     {
-        dead_band[ i ] = 0.0f;
-        saturate [ i ] = 1.0f;
+        joy->dead_band[ i ] = 0.0f;
+        joy->saturate [ i ] = 1.0f;
     }
 #   else
 
