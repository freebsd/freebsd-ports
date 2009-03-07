--- ./Core/DaemonState.cpp.orig	2009-03-05 15:22:25.000000000 +0100
+++ ./Core/DaemonState.cpp	2009-03-07 10:16:12.000000000 +0100
@@ -34,6 +34,9 @@
       #define CHECK_DISK_SPACE 1
     #else
       #ifdef HAVE_SYS_MOUNT_H
+	#if defined(__FreeBSD__) && (_FreeBSD_version < 700000)
+	  #include <sys/param.h>
+	#endif
         #include <sys/mount.h>
         #define CHECK_DISK_SPACE 1
       #endif
