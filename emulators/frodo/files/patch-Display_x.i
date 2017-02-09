--- Display_x.i.orig	2002-01-02 21:17:29 UTC
+++ Display_x.i
@@ -519,7 +519,7 @@ void C64Display::draw_led(int num, int s
  *  LED error blink
  */
 
-void C64Display::pulse_handler(...)
+void C64Display::pulse_handler(int sig)
 {
 	for (int i=0; i<4; i++)
 		switch (c64_disp->led_state[i]) {
