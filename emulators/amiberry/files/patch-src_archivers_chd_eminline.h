--- src/archivers/chd/eminline.h.orig	2026-04-14 16:02:12 UTC
+++ src/archivers/chd/eminline.h
@@ -23,8 +23,6 @@
 
 #if defined(__i386__) || defined(__x86_64__)
 #include "eigccx86.h"
-#elif defined(__ppc__) || defined (__PPC__) || defined(__ppc64__) || defined(__PPC64__)
-#include "eigccppc.h"
 #elif defined(__arm__) || defined(__aarch64__)
 #include "eigccarm.h"
 #endif
