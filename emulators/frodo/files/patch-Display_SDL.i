--- Display_SDL.i.orig	Wed Jan  2 22:42:42 2002
+++ Display_SDL.i	Sat Sep  6 07:54:35 2003
@@ -213,7 +213,7 @@
  *  LED error blink
  */
 
-void C64Display::pulse_handler(...)
+void C64Display::pulse_handler(int dummy)
 {
 	for (int i=0; i<4; i++)
 		switch (c64_disp->led_state[i]) {
