--- libwavplayclient/client.c.orig	2007-07-24 16:53:15.000000000 -0400
+++ libwavplayclient/client.c	2007-08-22 09:12:56.000000000 -0400
@@ -48,7 +48,6 @@
 #include <unistd.h>
 #include <errno.h>
 #include <time.h>
-#include <malloc.h>
 #include <string.h>
 #include <memory.h>
 #include <signal.h>
@@ -58,7 +57,7 @@
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <assert.h>
-#ifdef __CYGWIN__
+#if defined (__CYGWIN__) || defined (__FreeBSD__)
 #include <sys/soundcard.h>
 #else
 #include <linux/soundcard.h>
