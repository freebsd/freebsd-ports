--- gcc/protoize.c.orig	Mon Oct  9 18:37:32 1995
+++ gcc/protoize.c	Wed May 19 16:16:12 2004
@@ -22,6 +22,8 @@
    as __STDC__ plus more, so make sure that __STDC__ is defined if
    __cplusplus is defined. */
 
+#define HAS_STDARG_H
+
 #if defined(__cplusplus) && !defined(__STDC__)
 #define __STDC__ 1
 #endif /* defined(__cplusplus) && !defined(__STDC__) */
@@ -57,7 +59,9 @@
 #define _POSIX_SOURCE
 #endif
 
+#ifndef HAS_STDARG_H
 #include <varargs.h>
+#endif
 /* On some systems stdio.h includes stdarg.h;
    we must bring in varargs.h first.  */
 #include <stdio.h>
@@ -66,7 +70,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #ifndef _WIN32
-#if defined(POSIX) || defined(CONCURRENT)
+#if defined(POSIX) || defined(CONCURRENT) || defined (HAS_STDARG_H)
 #include <dirent.h>
 #else
 #include <sys/dir.h>
