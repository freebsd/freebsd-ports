--- ./Core/DaemonState.cpp.orig	2009-10-29 17:05:20.000000000 +0100
+++ ./Core/DaemonState.cpp	2009-11-14 14:24:21.000000000 +0100
@@ -37,7 +37,7 @@
       #define CHECK_DISK_SPACE 1
     #else
       #ifdef HAVE_SYS_MOUNT_H
-        #if defined(__OpenBSD__)
+        #if defined(__OpenBSD__) || (defined(__FreeBSD__) && (_FreeBSD_version < 700000))
           #include <sys/param.h>
         #endif
         #include <sys/mount.h>
