
$FreeBSD$

--- PowerMedia/mpeg.c	2002/04/17 15:58:59	1.1
+++ PowerMedia/mpeg.c	2002/04/17 16:03:52
@@ -16,7 +16,7 @@
 
 #ifdef USE_MPEG
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <smpeg.h>
 
 #include "powermedia.h"
@@ -210,7 +210,9 @@
 
 int PM_RenderMpegFrame (PD_Surface *Surface, PM_Mpeg *Mpeg, int Frame, int X, int Y)
 {
-   SMPEG_renderFrame(Mpeg->Mpeg, Frame, Surface, X, Y);
+   SMPEG_setdisplay(Mpeg->Mpeg, Surface, NULL, NULL);
+   SMPEG_move(Mpeg->Mpeg, X, Y);
+   SMPEG_renderFrame(Mpeg->Mpeg, Frame);
 
    return 0;
 }
