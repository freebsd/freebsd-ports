--- osdep/uade-os-unix.c.orig	Fri Aug 15 12:46:14 2003
+++ osdep/uade-os-unix.c	Fri Aug 15 12:49:28 2003
@@ -12,7 +12,7 @@
 #include <errno.h>
 #include <limits.h>
 
-#ifndef HAVE_MACOSX
+#if !defined(HAVE_MACOSX) && !defined(__FreeBSD__)
 #include <ftw.h>
 #endif
 
@@ -94,7 +94,7 @@
 static int (*uade_ftw_func) (const char *file, const struct stat *sb, int flag, void *arg);
 
 static int ftw_func(const char *file, const struct stat *sb, int flag) {
-#ifndef HAVE_MACOSX
+#if !defined(HAVE_MACOSX) && !defined(__FreeBSD__)
   switch (flag) {
   case FTW_F: flag = UADE_FTW_F; break;
   case FTW_D: flag = UADE_FTW_D; break;
@@ -120,10 +120,10 @@
 {
   uade_ftw_arg = arg;
   uade_ftw_func = fn;
-#ifndef HAVE_MACOSX
+#if !defined(HAVE_MACOSX) && !defined(__FreeBSD__)
   return ftw(dir, ftw_func, depth);
 #else
-  fprintf(stderr, "uade: error! macosx doesn't have uade_ftw() implemented\n");
+  fprintf(stderr, "uade: error! macosx & FreeBSD doesn't have uade_ftw() implemented\n");
   return 0;
 #endif
 }
