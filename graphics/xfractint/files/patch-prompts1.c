--- prompts1.c.orig	Tue Sep  7 00:38:10 1999
+++ prompts1.c	Sun Dec  7 02:48:35 2003
@@ -8,7 +8,7 @@
 #ifndef  __386BSD__
 #include <sys/types.h>
 #include <sys/stat.h>
-#ifndef __SVR4
+#if !defined(__SVR4) && !defined(__FreeBSD__)
 # include <sys/dir.h>
 #else
 # include <dirent.h>
@@ -20,7 +20,7 @@
 #endif
 #ifdef __TURBOC__
 #include <alloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
