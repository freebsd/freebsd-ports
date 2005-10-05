--- src/KXLjoystick.c.orig	Wed Oct  5 12:14:36 2005
+++ src/KXLjoystick.c	Wed Oct  5 12:15:19 2005
@@ -11,24 +11,7 @@
 //  return value : True - ok, False - NG
 //==============================================================
 Bool KXL_OpenJoystick(Uint8 *devname) {
-  Uint8 name[128] = "Unknown";
-  Sint32 version = 0x000800;
-  Uint8  axis = 2;
-  Uint8  buttons = 2;
-
-  KXL_joydev = open(devname, O_RDONLY);
-  if (KXL_joydev < 0) {
-    fprintf(stderr, "KXL error message\nCannot open \"%s\".\n", devname);
-    return False;
-  }
-  ioctl(KXL_joydev, JSIOCGVERSION, &version);
-  ioctl(KXL_joydev, JSIOCGAXES, &axis);
-  ioctl(KXL_joydev, JSIOCGBUTTONS, &buttons);
-  ioctl(KXL_joydev, JSIOCGNAME(128), name);
-  //fcntl(KXL_joydev, F_SETFL, O_NONBLOCK);
-  fprintf(stderr, "KXL message\nJoystick (%s) has %d axes and %d buttons.\nDriver version is %d.%d.%d.\n",
-	  name, axis, buttons, version >> 16, (version >> 8) & 0xff, version & 0xff);
-  return True;
+  return False;
 }
 
 //==============================================================
@@ -46,11 +29,4 @@
 //  return value : True - ok, False - NG
 //==============================================================
 Bool KXL_ReadJoystick(KXL_Joystick *my) {
-  if (KXL_joydev >= 0) {
-    if (read(KXL_joydev, my, JS_RETURN) == JS_RETURN) {
-      return True;
-    }
-  }
-  fprintf(stderr, "KXL error message\njoystick reading error\n");
-  return False;
 }
