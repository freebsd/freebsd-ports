--- source/creator/creator.c.orig	Fri Feb 14 22:11:48 2003
+++ source/creator/creator.c	Fri Feb 14 23:17:26 2003
@@ -91,6 +91,7 @@
 #ifdef __FreeBSD__
   #ifndef __OpenBSD__
     #include <floatingpoint.h>
+    #include <sys/types.h>
     #include <sys/rtprio.h>
   #endif
 #endif
