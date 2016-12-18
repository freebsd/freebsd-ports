--- src/common/atomic.h.orig	2009-03-29 18:43:39 UTC
+++ src/common/atomic.h
@@ -38,7 +38,7 @@
 #define CONFIG_SMP   /* ... the macro the kernel headers use */
 #endif
 
-#if defined(__linux__) || defined(WIN32) || defined(__APPLE__)
+#if defined(__linux__) || defined(WIN32) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #ifdef _ARCH_PPC
 
 /*
