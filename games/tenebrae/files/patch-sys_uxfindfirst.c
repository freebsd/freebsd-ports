--- sys_uxfindfirst.c.orig	2020-09-30 11:25:10 UTC
+++ sys_uxfindfirst.c
@@ -36,7 +36,7 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 #include "quakedef.h"
 #include <errno.h>
 
-#if !defined(__GLIBC__)
+#if !defined(__GLIBC__) && !defined(__FreeBSD__)
 
 #include <dirent.h>
 #include <fnmatch.h>
