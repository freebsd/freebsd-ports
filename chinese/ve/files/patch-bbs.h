--- bbs.h.orig	2009-10-06 23:10:03.000000000 +0800
+++ bbs.h	2009-10-06 23:14:01.000000000 +0800
@@ -12,6 +12,7 @@
 #define BIT8
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <setjmp.h>
 #include <signal.h>
 #include <unistd.h>
@@ -24,14 +25,7 @@
 #include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/file.h>
-
-
-#ifdef	LINUX
-#include <bsd/sgtty.h>
-#else
-#include <sgtty.h>
-#endif
-
+#include <termios.h>
 
 #ifdef  SYSV
 
