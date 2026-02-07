--- ./epi/endianess.h.orig	Sat Oct 14 05:10:38 2006
+++ ./epi/endianess.h	Wed Dec  5 23:19:09 2007
@@ -41,7 +41,11 @@
 // The macros used to swap values.  Try to use superfast macros on systems
 // that support them, otherwise use C++ inline functions.
 #ifdef LINUX
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 #ifdef __arch__swab16
 #define EPI_Swap16  __arch__swab16
 #endif
