--- nettest_unix.c	10 Mar 2001 13:04:39 -0000	1.1.1.2
+++ nettest_unix.c	21 Jan 2003 00:45:21 -0000
@@ -45,7 +45,8 @@
 #include <string.h>
 #include <time.h>
 #include <unistd.h>
-#ifndef __bsdi__
+#include <sys/param.h>
+#ifndef BSD
 #include <malloc.h>
 #endif
      
