$FreeBSD$

--- src/unix/video-drivers/xf86_dga1.c.orig	Sun Mar 20 22:10:35 2005
+++ src/unix/video-drivers/xf86_dga1.c	Sun Mar 20 22:12:24 2005
@@ -7,6 +7,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>

