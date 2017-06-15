--- Display.h.orig	2002-01-02 21:31:34 UTC
+++ Display.h
@@ -121,7 +121,7 @@ private:
 
 #ifdef __unix
 	void draw_led(int num, int state);	// Draw one LED
-	static void pulse_handler(...);		// LED error blinking
+	static void pulse_handler(int sig);	// LED error blinking
 #endif
 
 #ifdef WIN32
