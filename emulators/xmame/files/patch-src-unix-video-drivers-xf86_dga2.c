$FreeBSD$

--- src/unix/video-drivers/xf86_dga2.c.orig	Sun Mar 20 22:16:38 2005
+++ src/unix/video-drivers/xf86_dga2.c	Sun Mar 20 22:16:53 2005
@@ -10,6 +10,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>

