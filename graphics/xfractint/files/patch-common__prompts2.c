--- common/prompts2.c.orig	2011-05-08 10:20:02.000000000 -0500
+++ common/prompts2.c	2012-03-10 17:04:43.000000000 -0500
@@ -12,7 +12,7 @@
 
 #ifdef DIRENT
 #include <dirent.h>
-#elif !defined(__SVR4)
+#elif !defined(__SVR4) && !defined(__FreeBSD__)
 #include <sys/dir.h>
 #else
 #include <dirent.h>
@@ -26,7 +26,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
