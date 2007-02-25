--- ./engine/unix/linux_joystick.c.orig	Wed Dec 20 20:28:48 2006
+++ ./engine/unix/linux_joystick.c	Sat Dec 23 11:06:55 2006
@@ -31,8 +31,10 @@
 **
 */
 
-#ifndef __x86_64__
+#ifdef __linux__
 #include <linux/joystick.h>
+#elif defined(__FreeBSD__)
+#include <sys/joystick.h>
 #endif
 
 #include <sys/types.h>
@@ -72,7 +74,7 @@
 // bk001130 - from cvs1.17 (mkv), removed from linux_glimp.c
 void IN_StartupJoystick(void)
 {
-#ifndef __x86_64__
+#if defined(__linux__) || defined(__FreeBSD__)
 	int             i = 0;
 
 	joy_fd = -1;
@@ -87,20 +89,27 @@
 	{
 		char            filename[PATH_MAX];
 
+#ifdef __linux__
 		snprintf(filename, PATH_MAX, "/dev/js%d", i);
+#elif defined(__FreeBSD__)
+		snprintf(filename, PATH_MAX, "/dev/joy%d", i);
+#endif
 
 		joy_fd = open(filename, O_RDONLY | O_NONBLOCK);
 
 		if(joy_fd != -1)
 		{
+#ifdef __linux__
 			struct js_event event;
 			char            axes = 0;
 			char            buttons = 0;
 			char            name[128];
 			int             n = -1;
+#endif
 
 			Com_Printf("Joystick %s found\n", filename);
 
+#ifdef __linux__
 			/* Get rid of initialization messages. */
 			do
 			{
@@ -125,6 +134,7 @@
 			Com_Printf("Name:    %s\n", name);
 			Com_Printf("Axes:    %d\n", axes);
 			Com_Printf("Buttons: %d\n", buttons);
+#endif
 
 			/* Our work here is done. */
 			return;
@@ -143,7 +153,7 @@
 
 void IN_JoyMove(void)
 {
-#ifndef __x86_64__
+#if defined(__linux__) || defined(__FreeBSD__)
 	/* Store instantaneous joystick state. Hack to get around
 	 * event model used in Linux joystick driver.
 	 */
@@ -156,11 +166,16 @@
 	unsigned int    axes = 0;
 	int             i = 0;
 
+#ifdef __FreeBSD__
+	struct joystick event;
+#endif
+
 	if(joy_fd == -1)
 	{
 		return;
 	}
 
+#ifdef __linux__
 	/* Empty the queue, dispatching button presses immediately
 	 * and updating the instantaneous state for the axes.
 	 */
@@ -197,7 +212,19 @@
 		}
 
 	} while(1);
-
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
 	for(i = 0; i < 16; i++)
