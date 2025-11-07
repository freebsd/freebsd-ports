--- src/gldit/cairo-dock-file-manager.c.orig	2025-11-02 19:18:06 UTC
+++ src/gldit/cairo-dock-file-manager.c
@@ -22,7 +22,13 @@
 #include <string.h>      // memset
 #include <sys/stat.h>    // stat
 #include <fcntl.h>  // open
+#if defined (__FreeBSD__) || defined (__DragonFly__)
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/uio.h>
+#else
 #include <sys/sendfile.h>  // sendfile
+#endif
 #include <errno.h>  // errno
 
 #include "gldi-config.h"
@@ -492,7 +498,7 @@ gboolean cairo_dock_copy_file (const gchar *cFilePath,
 	{
 		// perform in-kernel transfer (zero copy to user space)
 		int size;
-		#ifdef __FreeBSD__
+		#if defined (__FreeBSD__) || defined (__DragonFly__)
 		size = sendfile (src_fd, dest_fd, 0, stat.st_size, NULL, NULL, 0);
 		#else  // Linux >= 2.6.33 for being able to have a regular file as the output socket
 		size = sendfile (dest_fd, src_fd, NULL, stat.st_size);  // note the inversion between both calls ^_^;
