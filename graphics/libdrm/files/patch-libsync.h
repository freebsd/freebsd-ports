# define ETIME as ETIMEOUT same as done in Mesa
#
--- libsync.h.orig	2017-04-14 23:29:46 UTC
+++ libsync.h
@@ -35,6 +35,9 @@
 #include <sys/ioctl.h>
 #include <sys/poll.h>
 #include <unistd.h>
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 
 #if defined(__cplusplus)
 extern "C" {
