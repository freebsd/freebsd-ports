--- libwavplayclient/wpc_msg.c.orig	2007-08-22 09:13:38.000000000 -0400
+++ libwavplayclient/wpc_msg.c	2007-08-22 09:13:52.000000000 -0400
@@ -4,7 +4,6 @@
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <malloc.h>
 #include <string.h>
 #include <memory.h>
 #include <signal.h>
@@ -13,7 +12,7 @@
 #include <sys/msg.h>
 #include <sys/ioctl.h>
 #include <assert.h>
-#ifdef __CYGWIN__
+#if defined (__CYGWIN__) || defined (__FreeBSD__)
 #include <sys/soundcard.h>
 #else
 #include <linux/soundcard.h>
