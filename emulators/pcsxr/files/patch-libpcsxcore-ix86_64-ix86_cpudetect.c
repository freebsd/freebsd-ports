--- libpcsxcore/ix86_64/ix86_cpudetect.c.orig	2018-06-07 22:29:16.208468000 +0200
+++ libpcsxcore/ix86_64/ix86_cpudetect.c	2018-06-07 22:31:35.845538000 +0200
@@ -145,7 +145,7 @@
 #endif
 }
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 
 #include <sys/time.h>
 #include <errno.h>
