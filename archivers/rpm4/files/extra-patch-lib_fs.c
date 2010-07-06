--- lib/fs.c.orig	2010-07-06 07:27:10.000000000 +0200
+++ lib/fs.c	2010-07-06 07:27:12.000000000 +0200
@@ -134,6 +134,8 @@ exit:
 
 #else	/* HAVE_MNTCTL */
 
+#include <sys/mount.h>
+
 /**
  * Get information for mounted file systems.
  * @todo determine rdonly for non-linux file systems.
