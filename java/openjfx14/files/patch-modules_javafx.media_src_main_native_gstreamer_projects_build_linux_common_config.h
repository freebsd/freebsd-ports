--- modules/javafx.media/src/main/native/gstreamer/gstreamer-lite/projects/build/linux/common/config.h.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.media/src/main/native/gstreamer/gstreamer-lite/projects/build/linux/common/config.h
@@ -376,7 +376,7 @@
 #define HAVE_SYS_POLL_H 1
 
 /* Define to 1 if you have the <sys/prctl.h> header file. */
-#define HAVE_SYS_PRCTL_H 1
+#undef HAVE_SYS_PRCTL_H
 
 /* Define to 1 if you have the <sys/resource.h> header file. */
 #undef HAVE_SYS_RESOURCE_H
