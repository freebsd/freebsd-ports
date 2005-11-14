--- xteddy.c.orig	Mon Nov 14 23:21:26 2005
+++ xteddy.c	Mon Nov 14 23:22:09 2005
@@ -17,7 +17,7 @@
 /* Changes: use Imlib instead of libxpm and load    *
  *          different image formats                 */
 
-#define DEFAULT_IMAGE_DIR "/usr/share/xteddy"
+#define DEFAULT_IMAGE_DIR "%%DATADIR%%"
 
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
