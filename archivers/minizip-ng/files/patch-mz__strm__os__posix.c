--- mz_strm_os_posix.c.orig	2026-01-21 21:52:59 UTC
+++ mz_strm_os_posix.c
@@ -21,6 +21,9 @@
 #include <errno.h>
 #include <unistd.h>  // open, close, ...
 #include <fcntl.h>   // O_NOFOLLOW, ...
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
 
 /***************************************************************************/
 
