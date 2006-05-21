--- ./QW/server/sys_unix.c.orig	Sat Feb 11 20:00:37 2006
+++ ./QW/server/sys_unix.c	Sun May 14 16:20:57 2006
@@ -25,7 +25,7 @@
 #include "server.h"
 #include "sys.h"
 
-#ifdef __linux__
+#ifdef __unix__
 #include <sys/stat.h>
 #include <unistd.h>
 #include <sys/time.h>
