--- ./common/prompts2.c.orig	2008-02-17 11:10:04.000000000 -0500
+++ ./common/prompts2.c	2010-01-27 13:52:46.000000000 -0500
@@ -12,7 +12,7 @@
 
 #ifdef DIRENT
 #include <dirent.h>
-#elif !defined(__SVR4)
+#elif !defined(__SVR4) && !defined(__FreeBSD__)
 #include <sys/dir.h>
 #else
 #include <dirent.h>
@@ -24,7 +24,7 @@
 #endif
 #ifdef __TURBOC__
 #include <alloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
