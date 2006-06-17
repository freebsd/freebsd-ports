--- ./sys_uxfindfirst.c.orig	Sat Jun 10 12:08:13 2006
+++ ./sys_uxfindfirst.c	Sat Jun 10 12:08:13 2006
@@ -36,7 +36,7 @@
 #include "quakedef.h"
 #include <errno.h>
 
-#if !defined(__GLIBC__)
+#if !defined(__GLIBC__) && !defined(__FreeBSD__)
 
 #include <dirent.h>
 #include <fnmatch.h>
