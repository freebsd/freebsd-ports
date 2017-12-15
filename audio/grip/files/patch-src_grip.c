--- src/grip.c.orig	2017-10-29 05:14:15 UTC
+++ src/grip.c
@@ -29,6 +29,7 @@
 #include <gdk/gdkx.h>
 #include <X11/Xlib.h>
 #include <time.h>
+#include <sys/wait.h>
 #include "grip.h"
 #include <libgnomeui/gnome-window-icon.h>
 #include "discdb.h"
