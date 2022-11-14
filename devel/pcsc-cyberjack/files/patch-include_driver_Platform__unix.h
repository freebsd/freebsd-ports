--- include/driver/Platform_unix.h.orig	2021-11-03 13:00:16 UTC
+++ include/driver/Platform_unix.h
@@ -40,7 +40,7 @@
 #include <string.h>
 #include <stdint.h>
 
-#ifndef OS_DARWIN
+#if !defined(OS_DARWIN) && !defined(OS_FREEBSD)
 # include <malloc.h>
 #endif
 
