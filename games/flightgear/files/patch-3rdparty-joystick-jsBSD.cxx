jsSetError() takes only two arguments (unlike ulSetError())

--- 3rdparty/joystick/jsBSD.cxx.orig	2018-05-28 23:22:56.449679000 +0200
+++ 3rdparty/joystick/jsBSD.cxx	2018-05-28 23:50:32.852422000 +0200
@@ -326,8 +289,8 @@
     error = ( joyfile == NULL ) ;
     if ( error )
     {
-      jsSetError ( SG_WARN, "unable to open calibration file %s (%s), joystick %i disabled (you can generate the calibration file with the plib-jscal utility)",
-		   joyfname, strerror ( errno ), id + 1 );
+      jsSetError ( SG_WARN, "unable to open calibration file, you can generate "
+        "the calibration file with the plib-jscal utility" );
       return ;
     }
 
