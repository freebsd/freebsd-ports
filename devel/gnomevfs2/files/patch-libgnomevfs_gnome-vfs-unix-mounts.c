--- libgnomevfs/gnome-vfs-unix-mounts.c.orig	Sun Sep  5 02:34:30 2004
+++ libgnomevfs/gnome-vfs-unix-mounts.c	Sun Sep  5 02:35:08 2004
@@ -43,6 +43,7 @@
 #include <errno.h>
 #include <string.h>
 #include <signal.h>
+#include <poll.h>
 #include <libgnomevfs/gnome-vfs.h>
 
 #include "gnome-vfs-unix-mounts.h"
