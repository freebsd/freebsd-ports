$FreeBSD$

--- ../../j2se/src/share/native/java/io/io_util.h	8 Nov 2004 22:27:35 -0000	1.1.1.1
+++ ../../j2se/src/share/native/java/io/io_util.h	7 Sep 2006 19:40:19 -0000
@@ -11,7 +11,15 @@
 extern jfieldID IO_fd_fdID;
 extern jfieldID IO_handle_fdID;
 
-#if !defined(O_DSYNC) || !defined(O_SYNC)
+#ifdef _ALLBSD_SOURCE
+#include <fcntl.h>
+#ifndef O_SYNC
+#define O_SYNC  O_FSYNC
+#endif
+#ifndef O_DSYNC
+#define O_DSYNC O_FSYNC
+#endif
+#elif !defined(O_DSYNC) || !defined(O_SYNC)
 #define O_SYNC  (0x0800)
 #define O_DSYNC (0x2000)
 #endif
