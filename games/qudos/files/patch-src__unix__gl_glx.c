--- ./src/unix/gl_glx.c.orig	Mon Jun  5 19:35:46 2006
+++ ./src/unix/gl_glx.c	Sun Jun 11 14:56:13 2006
@@ -1239,7 +1239,7 @@
 #endif
 		}
 #ifdef __FreeBSD__
-		else if (read(joy_fd, &j, sizeof(struct joystick)) != -1)
+		else if (read(joy_fd, &j, sizeof(struct joystick)) != -1) {
 #else
 		else {
 			while (read(joy_fd, &e, sizeof(struct js_event)) != -1 &&
