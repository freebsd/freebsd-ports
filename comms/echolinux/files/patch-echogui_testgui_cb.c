--- echogui/testgui_cb.c.orig	Tue Feb  3 03:28:03 2004
+++ echogui/testgui_cb.c	Mon Jul  5 00:14:13 2004
@@ -14,9 +14,10 @@
 #include <linux/soundcard.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#include <forms.h>
+#include <X11/forms.h>
 #include <math.h>
 #include <signal.h>
+#include <pthread.h>

 #include "testgui.h"
 #include "serverglobals.h"
@@ -345,6 +346,7 @@
 {
   int     error;
   char    line[3];
+  struct timeval timenow;
   struct timespec timeout;
 
   //  kill(controlPid, SIGKILL);
@@ -354,8 +356,9 @@
   line[1] = '\n';
   write(controlOutPipe[1], line, 2);
   
-  gettimeofday(&timeout);
-  timeout.tv_sec += 5;
+  gettimeofday(&timenow, NULL);
+  timeout.tv_sec = timenow.tv_sec + 5;
+  timeout.tv_nsec = 0;
   pthread_mutex_lock(&serverLoggedOffLock);
   sendServerCommand(LOGOFF);
   pthread_cond_timedwait(&serverLoggedOff, 
