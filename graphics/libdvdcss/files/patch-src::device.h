--- src/device.h.orig	Tue Aug 27 15:12:05 2002
+++ src/device.h	Tue Aug 27 15:13:30 2002
@@ -29,6 +29,7 @@
 #if defined( WIN32 )
 #   include <io.h>                                                 /* read() */
 #else
+#   include <sys/types.h>
 #   include <sys/uio.h>                                      /* struct iovec */
 #endif
 
