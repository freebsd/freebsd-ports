--- wrapper/glidesys.h.orig	Sun Jun 13 23:58:12 2004
+++ wrapper/glidesys.h	Thu Aug 12 17:14:11 2004
@@ -96,7 +96,7 @@
 #endif
 
 /* Check for OS */
-#if defined(__IRIX__) || defined(__sparc__) || defined(__linux__)
+#if defined(__IRIX__) || defined(__sparc__) || defined(__linux__) || defined(__FreeBSD__)
 #  define GLIDE_OS        GLIDE_OS_UNIX
 #elif defined(__DOS__)
 #  define GLIDE_OS        GLIDE_OS_DOS32
