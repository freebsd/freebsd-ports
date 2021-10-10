Fix build on FreeBSD

__unix__ is defined on FreeBSD and makes #elif __FreeBSD__ section skipped

--- test/common/utils_concurrency_limit.h.orig	2021-10-04 09:50:18 UTC
+++ test/common/utils_concurrency_limit.h
@@ -37,12 +37,11 @@
 #endif
 #include <string.h>
 #include <sched.h>
-#elif __FreeBSD__
-#include <unistd.h>
+#if __FreeBSD__
 #include <errno.h>
-#include <string.h>
 #include <sys/param.h>
 #include <sys/cpuset.h>
+#endif
 #endif
 #include <thread>
 
