diff --git a/src/libmongoc/src/mongoc/mongoc-counters-private.h b/src/libmongoc/src/mongoc/mongoc-counters-private.h
index ddd4d4954..c22908af0 100644
--- a/src/libmongoc/src/mongoc/mongoc-counters-private.h
+++ b/src/libmongoc/src/mongoc/mongoc-counters-private.h
@@ -28,6 +28,7 @@
 #include <sys/sysinfo.h>
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || \
    defined(__OpenBSD__)
+#include <sched.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/param.h>
