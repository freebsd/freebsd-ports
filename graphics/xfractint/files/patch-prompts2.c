--- prompts2.c.orig	Tue Sep  7 00:38:10 1999
+++ prompts2.c	Sun Dec  7 03:01:01 2003
@@ -9,7 +9,7 @@
 #elif !defined(__386BSD__)
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
 
