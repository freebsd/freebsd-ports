diff -ruN petit.orig/main.c petit/main.c
--- main.c.orig	Sat Nov 23 19:32:22 2002
+++ main.c	Thu Nov  6 13:21:06 2003
@@ -9,7 +9,7 @@
 #include <sys/time.h>
 #include <signal.h>
 #endif
-#if defined(__linux__) || defined(__os2__)
+#if defined(__linux__) || defined(__os2__) || defined (__FreeBSD__)
 #  define	min(x,y)	(((x)<(y))?(x):(y))
 #  define	max(x,y)	(((x)>(y))?(x):(y))
 #endif
