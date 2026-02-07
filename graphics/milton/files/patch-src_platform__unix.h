--- src/platform_unix.h.orig	2019-03-15 04:11:43 UTC
+++ src/platform_unix.h
@@ -1,7 +1,7 @@
 // Copyright (c) 2015 Sergio Gonzalez. All rights reserved.
 // License: https://github.com/serge-rgb/milton#license
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #ifndef _GNU_SOURCE
     #define _GNU_SOURCE  // To get MAP_ANONYMOUS on linux
     #endif
