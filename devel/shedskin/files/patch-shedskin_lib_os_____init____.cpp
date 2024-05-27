--- shedskin/lib/os/__init__.cpp.orig	2023-12-24 21:56:45 UTC
+++ shedskin/lib/os/__init__.cpp
@@ -27,7 +27,7 @@
 #include <sys/utsname.h>
 #include <sys/statvfs.h>
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <sys/sysmacros.h>
 #endif
 
@@ -42,6 +42,7 @@
 #ifdef __FreeBSD__
 #include <roken.h>
 #include <libutil.h>
+extern char **environ;
 #endif
 
 #ifdef __APPLE__
