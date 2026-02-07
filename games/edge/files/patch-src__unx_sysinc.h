--- ./src/unx_sysinc.h.orig	Mon May 28 00:01:49 2007
+++ ./src/unx_sysinc.h	Wed Dec  5 23:19:09 2007
@@ -23,7 +23,7 @@
 
 #include <sys/ioctl.h>
 
-#ifndef MACOSX
+#ifdef __linux__
 #include <linux/cdrom.h>
 #endif
 
