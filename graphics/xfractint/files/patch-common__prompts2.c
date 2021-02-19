--- common/prompts2.c.orig	2015-08-08 13:22:41 UTC
+++ common/prompts2.c
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
 
