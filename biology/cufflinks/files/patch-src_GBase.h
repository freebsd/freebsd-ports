--- src/GBase.h.orig	2019-05-25 22:08:19 UTC
+++ src/GBase.h
@@ -1,6 +1,6 @@
 #ifndef G_BASE_DEFINED
 #define G_BASE_DEFINED
-#ifndef _POSIX_SOURCE
+#if !defined(_POSIX_SOURCE) && !defined(__FreeBSD__)
 //mostly for MinGW
 #define _POSIX_SOURCE
 #endif
