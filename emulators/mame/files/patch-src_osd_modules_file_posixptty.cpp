--- src/osd/modules/file/posixptty.cpp.orig	2018-02-27 15:59:06 UTC
+++ src/osd/modules/file/posixptty.cpp
@@ -19,7 +19,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 
-#if defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <termios.h>
 #include <libutil.h>
 #elif defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__ANDROID__)
