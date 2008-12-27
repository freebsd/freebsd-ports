--- time.c.orig	2008-11-21 01:06:16.000000000 +0800
+++ time.c	2008-11-21 01:06:46.000000000 +0800
@@ -36,6 +36,7 @@
 #include <sys/timex.h>
 #include <linux/ioctl.h>
 #include <linux/rtc.h>
+#endif /* LINUX */
 
 #ifndef UTIME_NOW
 #define UTIME_NOW ((1l << 30) - 1l)
@@ -43,7 +44,6 @@
 #ifndef UTIME_OMIT
 #define UTIME_OMIT ((1l << 30) - 2l)
 #endif
-#endif /* LINUX */
 
 struct timeval32
 {
