--- unix/sys_unix.c.orig	Sun Dec 31 14:01:34 2006
+++ unix/sys_unix.c	Thu Mar 22 10:20:55 2007
@@ -35,6 +35,7 @@
 #include <sys/wait.h>
 #include <sys/mman.h>
 #include <errno.h>
+#include <sys/utsname.h>
 
 #if defined (__linux__)
 #include <mntent.h>
@@ -543,7 +544,6 @@
 
 void OS_Info(void) 
 {
-#include <sys/utsname.h>
 	struct utsname	info;
 	
 	uname (&info);
