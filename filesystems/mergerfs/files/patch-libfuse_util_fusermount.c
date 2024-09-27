--- libfuse/util/fusermount.c.orig	2024-02-29 20:41:22 UTC
+++ libfuse/util/fusermount.c
@@ -28,7 +28,12 @@
 #include <sys/fsuid.h>
 #include <sys/socket.h>
 #include <sys/utsname.h>
+#ifdef __linux__
 #include <sched.h>
+#else
+#define sched_getaffinity(pid, size, set) 0
+#define pthread_setaffinity_np(thread, size, set) 0
+#endif
 
 #define FUSE_COMMFD_ENV		"_FUSE_COMMFD"
 
