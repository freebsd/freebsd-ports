--- src/core/features.h.orig	2020-03-30 11:48:42 UTC
+++ src/core/features.h
@@ -29,8 +29,4 @@
 #define _POSIX_C_SOURCE 200112L
 #endif
 
-#ifndef _XOPEN_SOURCE
-#define _XOPEN_SOURCE 500
-#endif
-
 #endif
