--- libgnomevfs/gnome-vfs-hal-mounts.c.orig	Sun May  7 01:07:27 2006
+++ libgnomevfs/gnome-vfs-hal-mounts.c	Sun May  7 01:07:42 2006
@@ -32,7 +32,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>
+#ifdef HAVE_SYS_SYSMACROS_H
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 #include <limits.h>
