--- test/mtdev-test.c.orig	2014-02-28 18:48:23 UTC
+++ test/mtdev-test.c
@@ -28,11 +28,12 @@
 
 #include <mtdev.h>
 #include <stdio.h>
+#include <stdint.h>
 #include <unistd.h>
 #include <fcntl.h>
 
 /* year-proof millisecond event time */
-typedef __u64 mstime_t;
+typedef uint64_t mstime_t;
 
 static int use_event(const struct input_event *ev)
 {
