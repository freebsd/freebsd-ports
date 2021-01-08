--- mono/sgen/sgen-archdep.h.orig	2018-07-11 23:55:34 UTC
+++ mono/sgen/sgen-archdep.h
@@ -45,7 +45,7 @@

 #elif defined(TARGET_ARM64)

-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define REDZONE_SIZE    0
 #elif defined(__APPLE__)
 #define REDZONE_SIZE	128
