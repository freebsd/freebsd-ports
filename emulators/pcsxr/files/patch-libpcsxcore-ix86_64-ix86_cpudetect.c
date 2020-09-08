--- libpcsxcore/ix86_64/ix86_cpudetect.c.orig	2020-09-07 22:26:22 UTC
+++ libpcsxcore/ix86_64/ix86_cpudetect.c
@@ -145,7 +145,7 @@ u64 GetCPUTick( void ) 
 #endif
 }
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 
 #include <sys/time.h>
 #include <errno.h>
