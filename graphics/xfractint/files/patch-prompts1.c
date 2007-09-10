--- prompts1.c.orig	Mon Apr  8 19:33:28 2002
+++ prompts1.c	Mon Sep  3 19:16:50 2007
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
 
@@ -1980,7 +1980,7 @@
 /* subrtn of get_file_entry, separated so that storage gets freed up */
 {
 #ifdef XFRACT
-   static FCODE o_instr[]={"Press "FK_F6" to select different file, "FK_F2" for details,
+   static FCODE o_instr[]={"Press "FK_F6" to select different file, "FK_F2" for details, \
 "FK_F4" to toggle sort "};
 /* keep the above split on two lines, the carriage return is needed to keep the
    line length < 80 characters */
