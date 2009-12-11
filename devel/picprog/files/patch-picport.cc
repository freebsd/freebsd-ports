--- picport.cc.orig	2009-12-11 16:33:39.000000000 -0500
+++ picport.cc	2009-12-11 16:33:53.000000000 -0500
@@ -33,7 +33,6 @@
 #include <string>
 
 #include <sys/ioctl.h>
-#include <sys/io.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <time.h>
@@ -159,8 +158,6 @@
     // Not root.  Cannot use realtime scheduling.
     use_nanosleep = 0;
   }
-  if (iopl (3))
-    disable_interrupts = 0;
 
 #ifdef CPU_SETSIZE
   // When computing the delay loops, we do not want the cpu's to change.
