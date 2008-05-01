--- bbs.h.orig	2008-05-01 19:32:07.000000000 +0800
+++ bbs.h	2008-05-01 19:45:36.000000000 +0800
@@ -25,14 +25,6 @@
 #include <sys/stat.h>
 #include <sys/file.h>
 
-
-#ifdef	LINUX
-#include <bsd/sgtty.h>
-#else
-#include <sgtty.h>
-#endif
-
-
 #ifdef  SYSV
 
 #ifndef LOCK_EX
