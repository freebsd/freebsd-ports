
$FreeBSD$

--- Display.h.orig	Sat Nov 30 01:14:14 2002
+++ Display.h	Sat Nov 30 01:14:37 2002
@@ -112,7 +112,7 @@
 
 #ifdef __unix
 	void draw_led(int num, int state);	// Draw one LED
-	static void pulse_handler(...);		// LED error blinking
+	static void pulse_handler(int sig);	// LED error blinking
 #endif
 
 #ifdef WIN32
