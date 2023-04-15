--- src/i_fbsdvideo.c.orig	2023-04-15 12:37:20 UTC
+++ src/i_fbsdvideo.c
@@ -8,7 +8,7 @@
 #include <sys/fbio.h>
 #include <sys/kbio.h>
 #include <sys/consio.h>
-#include <sys/termios.h>
+#include <termios.h>
 #include <sys/mman.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -26,7 +26,7 @@
 #define RestorePalette()  SavRstPalette(FBIO_SETPALETTE)
 
 extern int usemouse;
-int mouse_scale_factor;
+extern int mouse_scale_factor;
 
 static event_t	event;
 
