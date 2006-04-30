--- libgnomevfs/gnome-vfs-volume-ops.c.orig	Wed Dec 14 22:20:23 2005
+++ libgnomevfs/gnome-vfs-volume-ops.c	Wed Dec 14 22:20:43 2005
@@ -25,6 +25,7 @@
 
 #include <sys/types.h>
 #include <errno.h>
+#include <signal.h>
 #include <string.h>
 #include <stdlib.h>
 #include <glib.h>
