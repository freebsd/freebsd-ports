--- engine/unix/linux_joystick.c.orig	Fri Apr 20 15:49:05 2007
+++ engine/unix/linux_joystick.c	Fri Apr 20 15:49:05 2007
@@ -32,7 +32,11 @@
 
 #if !USE_SDL_VIDEO
 
+#ifdef __linux__
 #include <linux/joystick.h>
+#elif defined(__FreeBSD__)
+#include <sys/joystick.h>
+#endif
 #include <sys/types.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
@@ -83,19 +87,26 @@
   for( i = 0; i < 4; i++ ) {
     char filename[PATH_MAX];
 
+#ifdef __linux__
     snprintf( filename, PATH_MAX, "/dev/js%d", i );
+#elif defined(__FreeBSD__)
+    snprintf( filename, PATH_MAX, "/dev/joy%d", i );
+#endif
 
     joy_fd = open( filename, O_RDONLY | O_NONBLOCK );
 
     if( joy_fd != -1 ) {
+#ifdef __linux__
       struct js_event event;
       char axes = 0;
       char buttons = 0;
       char name[128];
       int n = -1;
+#endif
 
       Com_Printf( "Joystick %s found\n", filename );
 
+#ifdef __linux__
       /* Get rid of initialization messages. */
       do {
 	n = read( joy_fd, &event, sizeof( event ) );
@@ -117,6 +128,7 @@
       Com_Printf( "Name:    %s\n", name );
       Com_Printf( "Axes:    %d\n", axes );
       Com_Printf( "Buttons: %d\n", buttons );
+#endif
 
       /* Our work here is done. */
       return;
@@ -144,10 +156,15 @@
   unsigned int axes = 0;
   int i = 0;
 
+#ifdef __FreeBSD__
+	struct joystick event;
+#endif
+
   if( joy_fd == -1 ) {
     return;
   }
 
+#ifdef __linux__
   /* Empty the queue, dispatching button presses immediately
 	 * and updating the instantaneous state for the axes.
 	 */
@@ -177,6 +194,19 @@
 
   } while( 1 );
 
+#elif defined(__FreeBSD__)
+	/*
+	 * FreeBSD does not fully support multi-buttoned joysticks.
+	 */
+	if (read(joy_fd, &event, sizeof(struct joystick)) != -1) {
+		if (event.b1)
+			Sys_QueEvent(0, SE_KEY, K_JOY1, 1, 0, NULL);
+		if (event.b2)
+			Sys_QueEvent(0, SE_KEY, K_JOY2, 1, 0, NULL);
+		axes_state[0] = event.x;
+		axes_state[1] = event.y;
+	}
+#endif
 
   /* Translate our instantaneous state to bits. */
   for( i = 0; i < 16; i++ ) {
