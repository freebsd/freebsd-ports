--- src/wl_init.c.orig	2019-08-03 17:40:05 UTC
+++ src/wl_init.c
@@ -29,7 +29,6 @@
 #include <assert.h>
 #include <errno.h>
 #include <limits.h>
-#include <linux/input.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -37,6 +36,15 @@
 #include <sys/timerfd.h>
 #include <unistd.h>
 #include <wayland-client.h>
+#ifdef __has_include
+#if __has_include(<linux/input.h>)
+#include <linux/input.h>
+#elif __has_include(<dev/evdev/input.h>)
+#include <dev/evdev/input.h>
+#endif
+#else
+#include <linux/input.h>
+#endif
 
 
 static inline int min(int n1, int n2)
