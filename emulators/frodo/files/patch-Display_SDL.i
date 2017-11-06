--- Display_SDL.i.orig	2002-01-02 21:42:42 UTC
+++ Display_SDL.i
@@ -213,7 +213,7 @@ void C64Display::draw_string(SDL_Surface
  *  LED error blink
  */
 
-void C64Display::pulse_handler(...)
+void C64Display::pulse_handler(int dummy)
 {
 	for (int i=0; i<4; i++)
 		switch (c64_disp->led_state[i]) {
