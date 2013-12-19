--- src/VBox/Main/src-server/freebsd/HostHardwareFreeBSD.cpp.orig	2012-12-19 19:27:17.000000000 +0100
+++ src/VBox/Main/src-server/freebsd/HostHardwareFreeBSD.cpp	2012-12-20 14:55:59.501850255 +0100
@@ -40,6 +40,7 @@
 # include <sys/stat.h>
 # include <unistd.h>
 # include <sys/ioctl.h>
+# include <stdio.h>
 # include <fcntl.h>
 # include <cam/cam.h>
 # include <cam/cam_ccb.h>
