--- src/include/port/freebsd.h.orig	Wed Jan  1 16:43:31 2003
+++ src/include/port/freebsd.h	Wed Jan  1 16:43:39 2003
@@ -7,6 +7,7 @@
 #if defined(__sparc__)
 #define NEED_SPARC_TAS_ASM
 #define HAS_TEST_AND_SET
+typedef unsigned char slock_t;
 #endif
 
 #if defined(__alpha__)
