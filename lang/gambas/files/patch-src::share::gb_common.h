--- ./src/share/gb_common.h.orig	Fri Mar  5 14:57:08 2004
+++ ./src/share/gb_common.h	Sat Jul 31 18:02:59 2004
@@ -58,6 +58,11 @@
   unsigned long ulong;
 #endif
 
+#ifdef __FreeBSD__
+/* Get definition for PATH_MAX */
+#include <limits.h>
+#endif
+
 #ifdef __sun__
  /* PGS: The following #define prevents /usr/include/sys/mman.h on solaris
     from #define'ing PRIVATE to 0x20, thus breaking Gambas.
