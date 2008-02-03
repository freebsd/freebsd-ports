--- ./UI/GTK2/src/DaemonState.cpp.orig	2007-12-13 05:16:01.000000000 +0100
+++ ./UI/GTK2/src/DaemonState.cpp	2008-02-03 11:13:45.000000000 +0100
@@ -33,6 +33,9 @@
       #define CHECK_DISK_SPACE 1
     #else
       #ifdef HAVE_SYS_MOUNT_H
+        #if defined(__FreeBSD__) && (_FreeBSD_version < 700000)
+          #include <sys/param.h>
+        #endif
         #include <sys/mount.h>
         #define CHECK_DISK_SPACE 1
       #endif
