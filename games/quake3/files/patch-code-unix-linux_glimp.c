diff -ruN ./code/unix/linux_glimp.c ../quake3-1.32b-BUILT/./code/unix/linux_glimp.c
--- ./code/unix/linux_glimp.c	Tue Aug 16 02:10:07 2005
+++ ../quake3-1.32b-BUILT/./code/unix/linux_glimp.c	Mon Aug 22 22:11:16 2005
@@ -1774,7 +1774,5 @@
 // bk010216 - added stubs for non-Linux UNIXes here
 // FIXME - use NO_JOYSTICK or something else generic
 
-#if defined( __FreeBSD__ ) // rb010123
 void IN_StartupJoystick( void ) {}
 void IN_JoyMove( void ) {}
-#endif
