$FreeBSD$

--- ../../j2se/src/share/native/java/io/io_util.h.orig	Wed Jul 21 08:32:49 2004
+++ ../../j2se/src/share/native/java/io/io_util.h	Wed Jul 21 08:37:54 2004
@@ -10,7 +10,15 @@
 
 extern jfieldID IO_fd_fdID;
 
-#if !defined(O_DSYNC) || !defined(O_SYNC)
+#ifdef _BSD_SOURCE
+#include <fcntl.h>
+#ifndef O_SYNC
+#define O_SYNC	O_FSYNC
+#endif
+#ifndef O_DSYNC
+#define O_DSYNC	O_FSYNC
+#endif
+#elif !defined(O_DSYNC) || !defined(O_SYNC)
 #define O_SYNC  (0x0800)
 #define O_DSYNC (0x2000)
 #endif
