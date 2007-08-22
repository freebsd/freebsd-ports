--- libwavplayclient/msg.c.orig	2007-08-22 09:16:53.000000000 -0400
+++ libwavplayclient/msg.c	2007-08-22 09:17:35.000000000 -0400
@@ -46,7 +46,6 @@
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <malloc.h>
 #include <string.h>
 #include <memory.h>
 #include <signal.h>
@@ -55,7 +54,7 @@
 #include <sys/msg.h>
 #include <sys/ioctl.h>
 #include <assert.h>
-#ifdef __CYGWIN__
+#if defined (__CYGWIN__) || defined(__FreeBSD__)
 #include <sys/soundcard.h>
 #else
 #include <linux/soundcard.h>
