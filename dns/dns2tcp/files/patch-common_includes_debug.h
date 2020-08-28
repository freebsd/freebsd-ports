--- common/includes/debug.h.orig	2020-08-28 19:24:48 UTC
+++ common/includes/debug.h
@@ -24,7 +24,7 @@
 #include <stdio.h>
 #include <time.h>
 
-int debug;
+extern int debug;
 
 #ifndef _WIN32
 #define DPRINTF(level, fmt, args...)  \
