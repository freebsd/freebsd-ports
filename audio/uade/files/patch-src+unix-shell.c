--- src/unix-shell.c.orig	Fri Aug 15 12:50:41 2003
+++ src/unix-shell.c	Fri Aug 15 12:51:37 2003
@@ -27,7 +27,7 @@
 #include "../osdep/strl.c"
 #include "unix-shell.h"
 
-#ifndef HAVE_MACOSX /* macosx doesn't have ftw. hell.. */
+#if !defined(HAVE_MACOSX) && !defined(__FreeBSD__)
 #include <ftw.h>
 #endif
 
@@ -58,7 +58,7 @@
   }
 }
 
-#ifndef HAVE_MACOSX
+#if !defined(HAVE_MACOSX) && !defined(__FreeBSD__)
 static int ftw_func(const char *file, const struct stat *sb, int flag, void *arg) {
   if (flag == UADE_FTW_F) {
     char name[PATH_MAX];
@@ -88,7 +88,7 @@
     return;
   }
 
-#ifndef HAVE_MACOSX
+#if !defined(HAVE_MACOSX) && !defined(__FreeBSD__)
   do {
     struct stat st;
     if (!stat(file, &st)) {
