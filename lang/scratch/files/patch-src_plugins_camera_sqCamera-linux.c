--- src/plugins/camera/sqCamera-linux.c.orig	2011-10-18 21:24:46 UTC
+++ src/plugins/camera/sqCamera-linux.c
@@ -45,8 +45,6 @@
 #include <sys/ioctl.h>
 #include <dlfcn.h>
 
-#include <asm/types.h>	  /* for videodev2.h */
-
 #include <linux/videodev2.h>
 
 
