--- ./src/unix/gl_glx.c.orig	Wed Mar 29 07:23:22 2006
+++ ./src/unix/gl_glx.c	Tue May 30 17:23:31 2006
@@ -1271,7 +1271,7 @@
 #endif
 		}
 #ifdef __FreeBSD__
-		else if (read(joy_fd, &j, sizeof(struct joystick)) != -1)
+		else if (read(joy_fd, &j, sizeof(struct joystick)) != -1) {
 #else
 		else {
 			while (read(joy_fd, &e, sizeof(struct js_event)) != -1 &&
