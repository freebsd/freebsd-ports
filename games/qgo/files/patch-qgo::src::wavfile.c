--- qgo/src/wavfile.c.orig	Mon Jun 23 23:57:08 2003
+++ qgo/src/wavfile.c	Fri Aug 20 23:10:57 2004
@@ -53,7 +53,6 @@
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <malloc.h>
 #include <string.h>
 #include <memory.h>
 #include <signal.h>
@@ -61,7 +60,7 @@
 #include <sys/ipc.h>
 #include <sys/ioctl.h>
 #include <assert.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 
 // stop
@@ -133,7 +132,7 @@
 //static ErrFunc _v_erf;				/* This module's error reporting function */
 static char emsg[2048];
 
-
+static void _v_erf(const char *format,va_list ap);
 
 /*
  * Error reporting function for this source module:
