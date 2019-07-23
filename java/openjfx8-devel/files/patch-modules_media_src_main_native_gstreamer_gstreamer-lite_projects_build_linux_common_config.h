--- modules/media/src/main/native/gstreamer/gstreamer-lite/projects/build/linux/common/config.h.orig	2019-07-22 15:39:06 UTC
+++ modules/media/src/main/native/gstreamer/gstreamer-lite/projects/build/linux/common/config.h
@@ -264,7 +264,7 @@
 #define HAVE_SYS_POLL_H 1
 
 /* Define to 1 if you have the <sys/prctl.h> header file. */
-#define HAVE_SYS_PRCTL_H 1
+#undef HAVE_SYS_PRCTL_H
 
 /* Define to 1 if you have the <sys/socket.h> header file. */
 #define HAVE_SYS_SOCKET_H 1
@@ -430,4 +430,4 @@
 /* Define to `unsigned int' if <sys/types.h> does not define. */
 /* #undef size_t */
 
-#define DISABLE_ORC
\ No newline at end of file
+#define DISABLE_ORC
