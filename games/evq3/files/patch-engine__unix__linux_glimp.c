--- engine/unix/linux_glimp.c.orig	Fri Apr 20 15:49:55 2007
+++ engine/unix/linux_glimp.c	Fri Apr 20 15:54:09 2007
@@ -2116,7 +2116,7 @@
 // bk010216 - added stubs for non-Linux UNIXes here
 // FIXME - use NO_JOYSTICK or something else generic
 
-#if (defined( __FreeBSD__ ) || defined( __sun)) // rb010123
+#if defined( __sun) // rb010123
 void IN_StartupJoystick( void ) {}
 void IN_JoyMove( void ) {}
 #endif
