$FreeBSD$

--- archive_platform.h.orig	Wed Apr  7 11:52:05 2004
+++ archive_platform.h	Wed Apr  7 11:52:32 2004
@@ -45,7 +45,9 @@
  */
 #include <inttypes.h>  /* For int64_t, etc. */
 
+#if __FreeBSD__ > 4
 #define HAVE_POSIX_ACL 1
+#endif
 #define HAVE_CHFLAGS 1
 #define HAVE_LUTIMES 1
 #define HAVE_LCHMOD 1
