--- src/linux/joystick.c.orig	Thu Jan 27 19:35:20 2005
+++ src/linux/joystick.c	Tue Sep 27 20:21:45 2005
@@ -75,7 +75,7 @@
   in_joystick = ri.Cvar_Get ("in_joystick", "1", CVAR_ARCHIVE);
   if (in_joystick->value) {
     joy_name = ri.Cvar_Get ("joy_name", "joystick", 0);
-    joy_dev = ri.Cvar_Get ("joy_dev","/dev/js*",CVAR_ARCHIVE);
+    joy_dev = ri.Cvar_Get ("joy_dev","/dev/joy*",CVAR_ARCHIVE);
     joy_advanced = ri.Cvar_Get ("joy_advanced","0",0);
     joy_advaxisx = ri.Cvar_Get ("joy_advaxisx","4",0);
     joy_advaxisy = ri.Cvar_Get ("joy_advaxisy","2",0);
