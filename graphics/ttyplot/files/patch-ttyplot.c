--- ttyplot.c.orig	2024-08-02 02:32:02 UTC
+++ ttyplot.c
@@ -9,7 +9,7 @@
 
 // This is needed on macOS to get the ncurses widechar API, and pkg-config fails to
 // define it.
-#ifdef __APPLE__
+#if defined (__APPLE__) || defined (__FreeBSD__)
 #define _XOPEN_SOURCE_EXTENDED
 #else
 // This is needed for musl libc
