
$FreeBSD$

--- Display_x.i.orig	Sat Nov 30 01:11:07 2002
+++ Display_x.i	Sat Nov 30 01:11:41 2002
@@ -525,7 +525,7 @@
  *  LED error blink
  */
 
-void C64Display::pulse_handler(...)
+void C64Display::pulse_handler(int sig)
 {
 	for (int i=0; i<4; i++)
 		switch (c64_disp->led_state[i]) {
