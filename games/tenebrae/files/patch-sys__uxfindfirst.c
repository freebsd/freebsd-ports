--- sys_uxfindfirst.c.orig	Sun Mar 14 15:00:09 2004
+++ sys_uxfindfirst.c	Sun Mar 14 15:06:52 2004
@@ -36,7 +36,7 @@
 #include "quakedef.h"
 #include <errno.h>
 
-#if !defined(__GLIBC__)
+#if !defined(__GLIBC__) && !defined(__FreeBSD__)
 
 #include <dirent.h>
 #include <fnmatch.h>
