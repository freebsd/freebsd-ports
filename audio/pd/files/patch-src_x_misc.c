--- src/x_misc.c.orig	Fri Nov 16 23:56:31 2001
+++ src/x_misc.c	Fri May 24 23:12:26 2002
@@ -10,6 +10,7 @@
 #include <string.h>
 #ifdef UNIX
 #include <sys/types.h>
+#include <sys/time.h>
 #include <sys/times.h>
 #include <sys/param.h>
 #endif
@@ -18,7 +19,7 @@
 #include <time.h>
 #endif
 
-#ifdef MACOSX
+#if defined (MACOSX) || defined (__FreeBSD__)
 #define HZ CLK_TCK
 #endif
 
