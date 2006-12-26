--- ./source/in_linux.c.orig	Mon Dec 25 17:07:02 2006
+++ ./source/in_linux.c	Mon Dec 25 17:07:03 2006
@@ -27,10 +27,14 @@
 #include <sys/ioctl.h>
 #include <unistd.h>
 #include <fcntl.h>
+#ifdef __linux__
 #include <linux/input.h>
+#endif
 #include <errno.h>
 
+#ifdef __linux__
 #include "SDL/SDL.h"
+#endif
 
 static cvar_t	*in_device;
 
@@ -38,6 +42,7 @@
 static qboolean mouseactive;
 static int      evdev_fd;
 
+#ifdef __linux__
 #define MAX_EVENTS    64
 #define EVENT_SIZE    sizeof( struct input_event )
 
@@ -223,5 +228,4 @@
 	api->Frame = Evdev_SendMouseMoveEvents;
 	api->ClearStates = Evdev_ClearMouseStates;
 }
-
-
+#endif
