
$FreeBSD$

--- src/video/svga/SDL_svgaevents.c	2001/01/27 17:53:11	1.1
+++ src/video/svga/SDL_svgaevents.c	2001/01/27 17:53:58
@@ -28,6 +28,7 @@
 /* Handle the event stream, converting X11 events into SDL events */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #include <vga.h>
 #include <vgamouse.h>
