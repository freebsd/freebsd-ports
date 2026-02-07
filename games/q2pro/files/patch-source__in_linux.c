--- source/in_linux.c.orig	Sun Jan 28 20:57:44 2007
+++ source/in_linux.c	Sun Feb  4 19:35:14 2007
@@ -27,10 +27,14 @@
 #include <sys/ioctl.h>
 #include <unistd.h>
 #include <fcntl.h>
+#ifdef __linux__
 #include <linux/input.h>
+#endif
 #include <errno.h>
 
+#ifdef __linux__
 #include <SDL.h>
+#endif
 
 static cvar_t	*in_device;
 
@@ -38,6 +42,7 @@
 static qboolean mouseactive;
 static int      evdev_fd;
 
+#ifdef __linux__
 #define MAX_EVENTS    64
 #define EVENT_SIZE    sizeof( struct input_event )
 
@@ -224,4 +229,4 @@
 	api->ClearStates = Evdev_ClearMouseStates;
 }
 
-
+#endif
