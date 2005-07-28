--- sim/arm/armdefs.h.orig	Wed May 11 22:10:09 2005
+++ sim/arm/armdefs.h	Sat Jul 16 18:25:48 2005
@@ -22,6 +22,13 @@
 #include <stdlib.h>
 #include <errno.h>
 
+
+#ifdef __FreeBSD__
+#include <sys/select.h>
+#define MAP_ANONYMOUS MAP_ANON
+#endif
+
+
 //teawater add for arm2x86 2005.02.14-------------------------------------------
 #include <sys/mman.h>
 //AJ2D--------------------------------------------------------------------------
@@ -63,6 +70,7 @@
 typedef unsigned char           uint8_t;
 typedef unsigned short          uint16_t;
 typedef unsigned int            uint32_t;
+typedef int            int32_t;
 #if defined (__x86_64__)
 typedef unsigned long           uint64_t;
 #else
