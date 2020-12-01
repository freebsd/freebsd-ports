--- src/drivers/Joystick.cpp	2020-11-10 01:04:17.000000000 -0500
+++ src/drivers/Joystick.cpp	2020-12-01 11:34:01.154240000 -0500
@@ -32,7 +32,7 @@
  #include "Joystick_SDL.h"
 #endif
 
-#ifdef HAVE_LINUX_JOYSTICK
+#if defined(HAVE_LINUX_JOYSTICK) && !defined(__FreeBSD__)
  #include "Joystick_Linux.h"
 #endif
 
@@ -175,7 +175,7 @@
 
  try
  {
-  #ifdef HAVE_LINUX_JOYSTICK
+  #if defined(HAVE_LINUX_JOYSTICK) && !defined(__FreeBSD__)
   main_driver = JoystickDriver_Linux_New();
   #elif defined(WIN32)
   {
