--- src/libmongoc/src/mongoc/mongoc-counters-private.h.orig	2023-01-03 15:52:22 UTC
+++ src/libmongoc/src/mongoc/mongoc-counters-private.h
@@ -28,6 +28,7 @@
 #include <sys/sysinfo.h>
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || \
    defined(__OpenBSD__)
+#include <sched.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/param.h>
