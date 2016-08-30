--- libelfsh/include/libelfsh-compat.h.orig	2003-08-21 01:11:03 UTC
+++ libelfsh/include/libelfsh-compat.h
@@ -10,7 +10,7 @@
 
 #if defined(__linux__)
  #include <endian.h>
-#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
  #include <machine/endian.h>
 #elif defined(sun)
  #define __LITTLE_ENDIAN 1234
@@ -38,7 +38,7 @@
 /* Portability Stuffs */
 #if defined(__OpenBSD__) || defined(__NetBSD__)
  #include <sys/exec_elf.h>
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(sun)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(sun) || defined(__DragonFly__)
  #include <elf.h>
 #endif
 
