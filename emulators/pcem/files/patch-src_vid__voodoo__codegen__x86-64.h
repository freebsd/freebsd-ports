--- src/vid_voodoo_codegen_x86-64.h.orig	2020-12-01 19:49:05 UTC
+++ src/vid_voodoo_codegen_x86-64.h
@@ -5,7 +5,7 @@
   fbzColorPath
 */
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 #endif
